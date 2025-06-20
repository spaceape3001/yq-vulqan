////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <tachyon/api/Delegate.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/meta/AssetProperty.hpp>
#include <tachyon/api/meta/DelegateProperty.hpp>
#include <tachyon/app/Application.hpp>
#include <tachyon/tags.hpp>
#include <yq/meta/ObjectInfo.hpp>
#include <yq/meta/PropertyInfo.hpp>
#include <tachyon/io/save/SaveAsset.hpp>
#include <tachyon/io/save/SaveDelegate.hpp>
#include <tachyon/io/save/SaveObject.hpp>
#include <tachyon/io/save/SaveTachyon.hpp>
#include <tachyon/io/save/SaveThread.hpp>
#include <yq/asset/Asset.hpp>
#include <yq/file/FileResolver.hpp>
#include <tachyon/command/tachyon/SetParentCommand.hpp>
#include <tachyon/command/thread/ScheduleCommand.hpp>
#include <tbb/spin_rw_mutex.h>
#include <tachyon/errors.hpp>

namespace yq::tachyon {
    static bool has_dotdot(const std::filesystem::path& fp)
    {
        for(auto& i : fp){
            if(i == "..")
                return true;
        }
        return false;
    }

    SaveObject* Save::samk(Save&save, const Object& obj)
    {
        typedef SaveObject* (*FN)(Save&, const Object&);
        static std::unordered_map<uint32_t, FN> s_functions;
        static tbb::spin_rw_mutex               s_mutex;
        
        FN  fn  = nullptr;
        
        {
            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, false);
            auto i = s_functions.find(obj.metaInfo().id());
            if(i != s_functions.end()){
                fn  = i->second;
            }
        }
        
        if(!fn){
            if(dynamic_cast<const Asset*>(&obj)){
                fn  = &Save::save_asset;
            } 
            
            if(dynamic_cast<const Delegate*>(&obj)){
                fn      = &Save::save_delegate;
            }
            
            if(dynamic_cast<const Tachyon*>(&obj)){
                if(dynamic_cast<const Thread*>(&obj)){
                    fn  = &Save::save_thread;
                } else {
                    fn  = &Save::save_tachyon;
                }
            }
            
            if(!fn){
                if(dynamic_cast<const UniqueID*>(&obj)){
                    fn      = &Save::save_object;
                } else {
                    fn      = &Save::save_nullptr;
                }
            }

            tbb::spin_rw_mutex::scoped_lock _lock(s_mutex, true);
            s_functions[obj.metaInfo().id()]    = fn;
        }
        
        return (*fn)(save, obj);
    }

    SaveObject* Save::save_asset(Save&save, const Object&obj)
    {
        return new SaveAsset(save, dynamic_cast<const Asset&>(obj));
    }
    
    SaveObject* Save::save_delegate(Save&save, const Object&obj)
    {
        return new SaveDelegate(save, dynamic_cast<const Delegate&>(obj));
    }
    
    SaveObject* Save::save_nullptr(Save&, const Object&)
    {
        return nullptr;
    }

    SaveObject* Save::save_object(Save&save, const Object&obj)
    {
        return new SaveObject(save, obj, dynamic_cast<const UniqueID&>(obj).id());
    }
    
    SaveObject* Save::save_tachyon(Save&save, const Object&obj)
    {
        return new SaveTachyon(save, dynamic_cast<const Tachyon&>(obj));
    }
    
    SaveObject* Save::save_thread(Save&save, const Object&obj)
    {
        return new SaveThread(save, dynamic_cast<const Thread&>(obj));
    }

    ////////////////////////////////////////////////////////////////////////////////

    Save::Save(SaveOptions opts) : m_options(opts)
    {
    }
    
    Save::~Save()
    {
        for(auto itr : m_objects){
            delete itr.second;
        }
        m_objects.clear();
    }

    void    Save::_bake()
    {
        //  currently nothing...but here nonetheless
    }

    void    Save::_prep()
    {
        if(m_prepped)
            return;
        m_assetPath = Asset::resolver().paths();
        m_prepped   = true;
        m_threads   = Thread::standard_thread_reverse_map();
    }

    void    Save::add_asset_path(const std::filesystem::path&fp)
    {
        _prep();
        m_assetPath.push_back(fp);
    }

    void    Save::add_variable(const std::string& k, Any&&v)
    {
        m_variables[k] = std::move(v);
    }

    SaveAsset*              Save::asset(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isAsset())
            return static_cast<SaveAsset*>(obj);
        return nullptr;
    }
    
    const SaveAsset*        Save::asset(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isAsset())
            return static_cast<const SaveAsset*>(obj);
        return nullptr;
    }

    void    Save::build()
    {
    }
    
    size_t                  Save::count(object_k) const
    {
        return m_objects.size();
    }

    SaveAsset*              Save::create(const AssetInfo*info, const std::filesystem::path& fp)
    {
        uint64_t id = 1+m_objects.size();
        SaveAsset* ret = new SaveAsset(*this, info, id, fp);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveDelegate*           Save::create(const DelegateInfo*info)
    {
        uint64_t id = 1+m_objects.size();
        SaveDelegate* ret = new SaveDelegate(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    
    #if 0
    SaveObject*             Save::create(const ObjectInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveObject* ret = new SaveObject(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    #endif
    
    SaveTachyon*            Save::create(const TachyonInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveTachyon* ret = new SaveTachyon(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }
    
    SaveThread*             Save::create(const ThreadInfo* info)
    {
        uint64_t id = 1+m_objects.size();
        SaveThread* ret = new SaveThread(*this, info, id);
        m_objects[id]   = ret;
        return ret;
    }

    SaveDelegate*           Save::delegate(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isDelegate())
            return static_cast<SaveDelegate*>(obj);
        return nullptr;
    }
    
    const SaveDelegate*     Save::delegate(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isDelegate())
            return static_cast<const SaveDelegate*>(obj);
        return nullptr;
    }

    SaveAsset*    Save::insert(const Asset& a)
    {
        return dynamic_cast<SaveAsset*>(saver(a));
    }
    
    SaveDelegate*    Save::insert(const Delegate&d)
    {
        return dynamic_cast<SaveDelegate*>(saver(d));
    }
    
    #if 0
    SaveObject*    Save::insert(const Object& obj)
    {
        return saver(obj);
    }
    #endif
    
    SaveTachyon*    Save::insert(const Tachyon& tac)
    {
        return dynamic_cast<SaveTachyon*>(saver(tac));
    }
    
    SaveThread*    Save::insert(const Thread&th)
    {
        return dynamic_cast<SaveThread*>(saver(th));
    }

    SaveObject*             Save::object(uint64_t i)
    {
        auto itr = m_objects.find(i);
        if(itr != m_objects.end())
            return itr->second;
        return nullptr;
    }
    
    const SaveObject*       Save::object(uint64_t i) const
    {
        auto itr = m_objects.find(i);
        if(itr != m_objects.end())
            return itr->second;
        return nullptr;
    }

    std::filesystem::path    Save::relativize(const std::filesystem::path&fp) const
    {
        for(const std::filesystem::path& dir : m_assetPath){
            std::filesystem::path rfile = fp.lexically_relative(dir);
            if(!has_dotdot(rfile))
                return rfile;
        }
        return fp;
    }
    
    SaveObject*             Save::saver(const Object& obj)
    {
        _prep();
        const UniqueID* uuid = dynamic_cast<const UniqueID*>(&obj);
        if(!uuid)
            return nullptr;
        
        auto [itr, ins]    = m_objects.emplace(uuid->id(), nullptr);
        if(ins){
            itr->second = samk(*this, obj);
            itr->second->m_remapId  = m_objects.size();
        }
        return itr->second;
    }

    std::optional<StdThread>    Save::std_thread(ThreadID id) const
    {
        auto i = m_threads.find(id);
        if(i!=m_threads.end())
            return i->second;
        return {};
    }
    
    SaveTachyon*            Save::tachyon(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isTachyon())
            return static_cast<SaveTachyon*>(obj);
        return nullptr;
    }
    
    const SaveTachyon*      Save::tachyon(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isTachyon())
            return static_cast<const SaveTachyon*>(obj);
        return nullptr;
    }
    
    SaveThread*             Save::thread(uint64_t i)
    {
        SaveObject* obj = object(i);
        if(obj && obj -> isThread())
            return static_cast<SaveThread*>(obj);
        return nullptr;
    }
    
    const SaveThread*       Save::thread(uint64_t i) const
    {
        const SaveObject* obj = object(i);
        if(obj && obj -> isThread())
            return static_cast<const SaveThread*>(obj);
        return nullptr;
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    
    namespace errors {
        using namespace ::yq::errors;
        
        using bad_asset             = error_db::entry<"Save unable to create asset">;
        using bad_delegate          = error_db::entry<"Save unable to create delegate">;
        using bad_tachyon           = error_db::entry<"Save unable to create tachyon">;
        using bad_thread            = error_db::entry<"Save unable to create thread">;
        using bad_parent            = error_db::entry<"Save unable to associate tachyon's parent">;
        using bad_owner             = error_db::entry<"Save unable to associate tachyon's owner">;
        using invalid_id_property   = error_db::entry<"Bad ID property">;
        using null_application      = error_db::entry<"Application not found">;
        using null_frame            = error_db::entry<"Requested frame not found">;
        using null_owner            = error_db::entry<"Requested owner not found">;
        using null_parent           = error_db::entry<"Requested parent not found">;
    }

    struct Save::Reincarnator {
        struct asset_t {
            const SaveAsset*    save    = nullptr;
            AssetCPtr           asset;
        };
    
        struct delegate_t {
            const SaveDelegate* save  = nullptr;
            DelegatePtr         delegate;
        };
    
        struct tachyon_t {
            const SaveTachyon*  save    = nullptr;
            TachyonPtr          tachyon;
            bool                nullpar = false;
        };
        
        struct thread_t {
            const SaveThread*   save    = nullptr;
            ThreadPtr           thread;
            TachyonPtrVector    tachyons;
        };
    
        const Save&                             m_save;
        const ReincarnationConfig&              m_config;
        std::map<uint64_t, asset_t>             m_assets;
        std::map<uint64_t, delegate_t>          m_delegates;
        std::map<uint64_t, tachyon_t>           m_tachyons;
        std::map<uint64_t, thread_t>            m_threads;
        std::map<uint64_t, ThreadID>            m_threadIds;
        std::map<ThreadID, TachyonPtrVector>    m_byThread; // zero is for those w/o threads
        std::map<StdThread, TachyonPtrVector>   m_stdThread;
        std::vector<TachyonID>                  m_topChild; //!< Top level child to what was passed in
        bool                                    m_threading;
        
        Tachyon*      tachyon_ptr(uint64_t i)
        {
            auto itr = m_tachyons.find(i);
            if(itr != m_tachyons.end())
                return itr->second.tachyon.ptr();
            return nullptr;
        }
        
        
        Reincarnator(const Save& save, const ReincarnationConfig& cfg, bool threading) : 
            m_save(save), m_config(cfg), m_threading(threading)
        {
        }
        
        std::error_code load_attributes(Tachyon* tac, const SaveTachyon& sv)
        {
            //  TODO ... prog & user attributes with tachyon IDs
            tac -> load_attributes(sv.prog_attributes());
            tac -> load_attributes(sv.user_attributes());
            return {};
        }
        
        std::error_code load_properties(Object* obj, const SaveObject& sv)
        {
            std::error_code ec;
            std::set<const PropertyInfo*>   remaining;
            for(const PropertyInfo* pi : sv.info()->properties(ALL).all){
                if(pi->tagged(kTag_Save) && pi->setter())
                    remaining.insert(pi);
            }
            
            for(auto& p : sv.properties()){
                if(!p.info)
                    continue;
                remaining.erase(p.info);
                
                if(p.isTachID){
                    uint64_t    id      = p.value.value<uint64_t>();
                    if(p.info->type().id() == meta<TypedID>().id()){
                        const Tachyon* t    = tachyon_ptr(id);
                        if(!t)
                            return errors::invalid_id_property();
                        ec  = p.info->set(obj, Any(TypedID(*t)));
                    } else {
                        any_x       value   = p.info->type().construct(id);
                        if(!value)
                            return errors::invalid_id_property();
                        ec  = p.info->set(obj, *value);
                    }
                } else 
                    ec = p.info->set(obj, p.value);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(const PropertyInfo* pi : remaining){
                ec = pi->set(obj, DEFAULT);
                if(ec != std::error_code())
                    return ec;
            }
        
            return {};
        }
        
        std::error_code load_assets(Tachyon* tac, const SaveTachyon& sv)
        {
            std::error_code ec;
            for(auto& p : sv.assets()){
                if(!p.info)
                    continue;
                if(!p.asset)
                    continue;
                
                auto a  = m_assets.find(p.asset->id());
                if(a == m_assets.end())
                    return errors::bad_asset();

                ec = p.info->set(tac, a->second.asset);
                if(ec != std::error_code())
                    return ec;
            }
        
            return {};
        }

        std::error_code load_delegates(Tachyon* tac, const SaveTachyon& sv)
        {
            std::error_code ec;
            for(auto& p : sv.delegates()){
                if(!p.info)
                    continue;
                if(!p.delegate)
                    continue;
                
                auto d = m_delegates.find(p.delegate->id());
                if(d == m_delegates.end())
                    return errors::bad_delegate();
                
                ec = p.info->set(tac, d->second.delegate);
                if(ec != std::error_code()) 
                    return ec;
            }
            return {};
        }
        
        std::error_code define_parent(tachyon_t& tac)
        {
            if(!tac.save)
                return errors::null_pointer();
            if(!tac.tachyon)
                return errors::null_pointer();
            
            uint64_t p  = tac.save->parent();
            if(!p){
                tac.nullpar     = true;
                return {};
            }
            
            auto i  = m_tachyons.find(p);
            if(i == m_tachyons.end())
                return errors::bad_parent();
            
            tac.tachyon->load_set_parent(i->second.tachyon->id(TYPED));
            i->second.tachyon->load_add_child(tac.tachyon->id(TYPED));
            return {};
        }

        std::error_code define_owner(tachyon_t& tac)
        {
            if(!tac.save)
                return errors::null_pointer();
            if(!tac.tachyon)
                return errors::null_pointer();
            
            if(auto p = std::get_if<StdThread>(&tac.save->owner())){
                m_stdThread[*p].push_back(tac.tachyon);
            } else if(auto p = std::get_if<uint64_t>(&tac.save->owner())){
                auto i = m_threads.find(*p);
                if(i != m_threads.end())
                    return errors::bad_owner();
                if(!i->second.thread)
                    return errors::bad_owner();
                m_byThread[i->second.thread->id()].push_back(tac.tachyon);
            } else {
                // TODO... (really shouldn't exist...still)
                return errors::todo();
            }
            return {};
        }

        std::error_code create(asset_k, const SaveAsset* sv)
        {
            if(!sv->info())
                return errors::null_pointer();
            AssetCPtr   ass = sv->info()->load(sv->filepath().string());
            if(!ass)
                return errors::bad_asset();
                
            auto& ret       = m_assets[sv->id()];
            ret.save        = sv;
            ret.asset       = ass;
            return {};
        }
        
        std::error_code create(delegate_k, const SaveDelegate* sv)
        {
            if(!sv->info())
                return errors::null_pointer();

            Object*     op  = sv->info()->create();
            if(!op)
                return errors::bad_delegate();

            DelegatePtr  del  = dynamic_cast<Delegate*>(op);
            if(!del){
                delete op;
                return errors::bad_delegate();
            }
            
            auto& ret       = m_delegates[sv->id()];
            ret.save        = sv;
            ret.delegate    = del;
            return {};
        }

        std::error_code create(object_k, const SaveObject* sv)
        {
            if(!sv->info())
                return errors::null_pointer();
            return errors::todo();
        }

        std::error_code create(tachyon_k, const SaveTachyon* sv)
        {
            if(!sv->info())
                return errors::null_pointer();

            Object*     op  = sv->info()->create();
            if(!op)
                return errors::bad_tachyon();

            TachyonPtr  tp  = dynamic_cast<Tachyon*>(op);
            if(!tp){
                delete op;
                return errors::bad_tachyon();
            }
            
            auto& ret       = m_tachyons[sv->id()];
            ret.save        = sv;
            ret.tachyon     = tp;
            return {};
        }

        std::error_code create(thread_k, const SaveThread* sv)
        {
            if(!sv->info())
                return errors::null_pointer();

            Object*     op  = sv->info()->create();
            if(!op)
                return errors::bad_thread();

            ThreadPtr   tp  = dynamic_cast<Thread*>(op);
            if(!tp){
                delete op;
                return errors::bad_thread();
            }
            
            auto& ret       = m_threads[sv->id()];
            ret.save        = sv;
            ret.thread      = tp;
            m_threadIds[sv->id()]   = ret.thread->id();
            return {};
        }

        std::error_code build()
        {
            std::error_code ec;
            for(auto& itr : m_save.m_objects){
                if(!itr.second)
                    continue;

                switch(itr.second->saveType()){
                case SaveType::Asset:
                    ec  = create(ASSET, static_cast<const SaveAsset*>(itr.second));
                    break;
                case SaveType::Delegate:
                    ec  = create(DELEGATE, static_cast<const SaveDelegate*>(itr.second));
                    break;
                case SaveType::Object:
                    ec  = create(OBJECT, itr.second);
                    break;
                case SaveType::Tachyon:
                    ec  = create(TACHYON, static_cast<const SaveTachyon*>(itr.second));
                    break;
                case SaveType::Thread:
                    ec  = create(THREAD, static_cast<const SaveThread*>(itr.second));
                    break;
                default:
                    ec  = errors::todo();
                    break;
                }
                
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_delegates){
                ec = load_properties(itr.second.delegate.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_tachyons){
                ec = load_properties(itr.second.tachyon.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
                ec = load_attributes(itr.second.tachyon.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_threads){
                ec = load_properties(itr.second.thread.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
                ec = load_attributes(itr.second.thread.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_tachyons){
                ec = load_assets(itr.second.tachyon.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_threads){
                ec = load_assets(itr.second.thread.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }
            
            for(auto& itr : m_tachyons){
                ec = load_delegates(itr.second.tachyon.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }

            for(auto& itr : m_threads){
                ec = load_delegates(itr.second.thread.ptr(), *itr.second.save);
                if(ec != std::error_code())
                    return ec;
            }

            for(auto& itr : m_tachyons){
                ec = define_parent(itr.second);
                if(ec != std::error_code())
                    return ec;
            }
            
            if(m_threading && std::get_if<std::monostate>(&m_config.owner) && !m_config.parent){
                for(auto& itr : m_tachyons){
                    ec = define_owner(itr.second);
                    if(ec != std::error_code())
                        return ec;
                }
            }
            
            return {};
        }
        
        void    extract(TachyonPtrVector& tachs)
        {
            tachs.reserve(m_tachyons.size());
            for(auto& itr : m_tachyons)
                tachs.push_back(itr.second.tachyon);
        }
    };
    
    std::error_code         Save::execute(TachyonPtrVector& tachs, const ReincarnationConfig& config) const
    {
        Reincarnator    exec(*this, config, false);
        
        std::error_code ec  = exec.build();
        if(ec != std::error_code())
            return ec;
        
        exec.extract(tachs);
        return {};
    }
    
    std::error_code         Save::execute(schedule_k, const ReincarnationConfig& config, TachyonIDSet* pIDs) const
    {
        Reincarnator    exec(*this, config, true);
        std::error_code ec  = exec.build();
        if(ec != std::error_code())
            return ec;
            
        // Scheduling....
        if(config.parent){
            const Frame* frame  = Frame::current();
            if(!frame)
                return errors::null_frame();
                
            //  alright, all things a go....
            ThreadID        owner   = frame->owner(config.parent);
            if(!owner)
                return errors::null_parent();
            
            TypedID         ownerT( owner.id, Type::Thread );
            
            TachyonPtrVector    tachyons;
            exec.extract(tachyons);
            if(pIDs){
                for(TachyonPtr& tp : tachyons)
                    pIDs->insert(tp->id());
            }
            
            for(auto & itr : exec.m_tachyons){
                if(itr.second.nullpar){
                    itr.second.tachyon->set_parent(config.parent);
                }
            }
            
            Tachyon::mail(owner, new ScheduleCommand({.target=ownerT}, std::move(tachyons)));
            return {};
        } else if(auto p = std::get_if<StdThread>(&config.owner)){
            ThreadID        owner   = Thread::standard(*p);
            if(!owner)
                return errors::null_owner();
            TypedID         ownerT( owner.id, Type::Thread );
                
            TachyonPtrVector    tachyons;
            exec.extract(tachyons);
            if(pIDs){
                for(TachyonPtr& tp : tachyons)
                    pIDs->insert(tp->id());
            }

            Tachyon::mail(owner, new ScheduleCommand({.target=ownerT}, std::move(tachyons)));
            return {};
        } else if(auto p = std::get_if<ThreadID>(&config.owner)){
            ThreadID        owner   = *p;
            TachyonPtrVector    tachyons;
            TypedID         ownerT( owner.id, Type::Thread );
            exec.extract(tachyons);
            if(pIDs){
                for(TachyonPtr& tp : tachyons)
                    pIDs->insert(tp->id());
            }

            Tachyon::mail(owner, new ScheduleCommand({.target=ownerT}, std::move(tachyons)));
            return {};
        } else {
            if(!exec.m_threads.empty()){
                Application* app    = Application::app();
                if(!app)
                    return errors::null_application();
                for(auto& th : exec.m_threads)
                    app->start_thread(th.second.thread);
            }
            
            // TODO
        }
        
        return errors::todo();
    }
}
