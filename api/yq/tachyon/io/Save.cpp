////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yq/tags.hpp>
#include <yq/core/Any.hpp>
#include <yq/container/Map.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Delegate.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/meta/DelegateProperty.hpp>
#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/command/tachyon/SetParentCommand.hpp>
#include <yq/tachyon/command/thread/ScheduleCommand.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Save)

namespace yq::tachyon {
    namespace errors {
        using namespace ::yq::errors;
        
        using bad_resource          = error_db::entry<"Save unable to create resource">;
        using bad_delegate          = error_db::entry<"Save unable to create delegate">;
        using bad_tachyon           = error_db::entry<"Save unable to create tachyon">;
        using bad_thread            = error_db::entry<"Save unable to create thread">;
        using bad_parent            = error_db::entry<"Save unable to associate tachyon's parent">;
        using bad_owner             = error_db::entry<"Save unable to associate tachyon's owner">;
        using bad_property          = error_db::entry<"Save unable to associate object's property">;
        using invalid_id_property   = error_db::entry<"Bad ID property">;
        using null_application      = error_db::entry<"Application not found">;
        using null_frame            = error_db::entry<"Requested frame not found">;
        using null_owner            = error_db::entry<"Requested owner not found">;
        using null_parent           = error_db::entry<"Requested parent not found">;
        using duplicate_id          = error_db::entry<"Duplicate ID detected">;
    }

    namespace {
        void    export_object(ObjectSave& sv, Save& ss, const Object& obj)
        {
            sv.class_    = std::string(obj.metaInfo().name());
            for(const PropertyMeta* p : obj.metaInfo().properties(ALL).all){
                if(!p->setter())   // it's read-only
                    continue;
                if(!p->tagged(kTag_Save))
                    continue;
                any_x   val = p->get(&obj);
                if(!val)
                    continue;
                if(p->is_default(*val))
                    continue;

                if(p->tagged(kTag_TachyonID)){
                    TachyonID   tid = (*val).value<TachyonID>();
                    sv.properties[std::string(p->name())] = (uint64_t) tid;
                } else {
                    sv.properties[std::string(p->name())] = std::move(*val);
                }
            }
        }

        void    export_delegate(DelegateSave& sv, Save& ss, const Delegate& dlg)
        {
            export_object(sv, ss, dlg);
            sv.id      = dlg.id();
            if(!ss.flags(SaveFlag::SkipState))
                dlg.save(sv);
        }

        void    export_tachyon(TachyonSave& sv, Save& ss, const Tachyon& tac, bool isThread=false)
        {
            static const StdThreadRevMap threads  = Thread::standard_thread_reverse_map();

            export_object(sv, ss, tac);
            sv.id       = tac.id();
            sv.uattrs   = tac.user_attributes();
            sv.pattrs   = tac.prog_attributes();

            if(!isThread){
                if(!ss.flags(SaveFlag::SkipOwnership)){
                    ThreadID    owner   = tac.owner();
                    auto x = threads.find(owner);
                    if(x != threads.end()){
                        sv.owner    = x->second;
                    } else if(owner)
                        sv.owner    = owner;
                }
            
                sv.parent   = tac.parent();
                for(auto& ch : tac.children())
                    sv.children.push_back(ch);
            }
            
            for(const ResourceProperty* r : tac.metaInfo().resources(ALL).all){
                ResourceCPtr   res   = r->get(&tac);
                if(!res)
                    continue;
                sv.resources[std::string(r->name())] = res->url();
            }
            
            for(const DelegateProperty* d : tac.metaInfo().delegates(ALL).all){
                DelegateCPtr    delegate = d->get(&tac);
                if(!delegate)
                    continue;
                if(!ss.delegates.byId.contains(delegate->id()))
                    ss._delegate(*delegate);
                sv.delegates[std::string(d->name())] = delegate->id();
            }
            
            if(!ss.flags(SaveFlag::SkipState))
                tac.save(sv);
        }

        void    export_thread(ThreadSave& sv, Save& ss, const Thread& th)
        {
            export_tachyon(sv, ss, th, true);
        }
    }


    void    Save::init_meta()
    {
        auto w  = writer<Save>();
        w.description("Tachyon Save");
        w.property("type", &Save::type).tag({kTag_Log});
    }

    Save::Save()
    {
    }
    
    Save::~Save()
    {
    }

    DelegateSave&   Save::_delegate(const Delegate& dlg)
    {
        size_t  n   = delegates.data.size();
        delegates.data.push_back({});
        DelegateSave&   ret = delegates.data.back();
        export_delegate(ret, *this, dlg);
        delegates.byId[ret.id]      = n;
        return ret;
    }
    
    TachyonSave&    Save::_tachyon(const Tachyon&tac)
    {
        size_t  n   = tachyons.data.size();
        tachyons.data.push_back({});
        TachyonSave&   ret = tachyons.data.back();
        export_tachyon(ret, *this, tac);
        tachyons.byId[ret.id]      = n;
        return ret;
    }
    
    ThreadSave&     Save::_thread(const Thread& th)
    {
        size_t  n   = threads.data.size();
        threads.data.push_back({});
        ThreadSave&   ret = threads.data.back();
        export_thread(ret, *this, th);
        threads.byId[ret.id]      = n;
        return ret;
    }

    Save&   Save::operator<<(const Object&  obj)
    {
        add(obj);
        return *this;
    }


    void    Save::add(const Object& obj)
    {
        if(const Thread*p = dynamic_cast<const Thread*>(&obj)){
            _thread(*p);
        } else if(const Tachyon*p = dynamic_cast<const Tachyon*>(&obj)){
            _tachyon(*p);
        } else if(const Delegate*p = dynamic_cast<const Delegate*>(&obj)){
            _delegate(*p);
        }
    }

    size_t  Save::count(delegate_k) const
    {
        return delegates.data.size();
    }
    
    size_t  Save::count(tachyon_k) const
    {
        return tachyons.data.size();
    }
    
    size_t  Save::count(thread_k) const
    {
        return threads.data.size();
    }

    size_t  Save::data_size() const 
    {
        return 0; // TODO
    }


    const DelegateSave* Save::delegate(uint64_t i) const
    {
        auto x = delegates.byId.find(i);
        if(x == delegates.byId.end())
            return nullptr;
        if(x->second >= delegates.data.size())
            return nullptr;
        return &delegates.data[x->second];
    }
    
    const TachyonSave*  Save::tachyon(uint64_t i) const
    {
        auto x = tachyons.byId.find(i);
        if(x == tachyons.byId.end())
            return nullptr;
        if(x->second >= tachyons.data.size())
            return nullptr;
        return &tachyons.data[x->second];
    }
    
    const ThreadSave*   Save::thread(uint64_t i) const
    {
        auto x = threads.byId.find(i);
        if(x == threads.byId.end())
            return nullptr;
        if(x->second >= threads.data.size())
            return nullptr;
        return &threads.data[x->second];
    }


    //////////////////////////////////////
    struct Save::Reincarnator {
        //  --------------------
        // structures
        struct delegate_t {
            const DelegateSave*     save    = nullptr;
            DelegatePtr             delegate;
        };
        
        struct tachyon_t {
            const TachyonSave*      save    = nullptr;
            TachyonPtr              tachyon;
        };
        
        struct thread_t {
            const ThreadSave*       save    = nullptr;
            ThreadPtr               thread;
        };
        
        
        //  --------------------
        //  temporary data
        const Save&                             m_save;
        const ReincarnationConfig&              m_config;
        bool                                    m_threading;

        std::map<uint64_t, delegate_t>          m_delegates;
        std::map<uint64_t, tachyon_t>           m_tachyons;
        std::map<uint64_t, thread_t>            m_threads;
        std::map<uint64_t, ThreadID>            m_threadIds;
        std::map<ThreadID, TachyonPtrVector>    m_byThread; // zero is for those w/o threads
        std::map<StdThread, TachyonPtrVector>   m_stdThread;
        std::vector<TachyonID>                  m_topChild; //!< Top level child to what was passed in
        std::map<uint64_t,uint64_t>             m_remap;
        std::map<uint64_t,Delegate*>            m_old2delegate;
        std::map<uint64_t,Tachyon*>             m_old2tachyon;
        std::map<uint64_t,Thread*>              m_old2thread;

        Delegate*        _old(delegate_k, uint64_t i) const
        {
            auto x = m_old2delegate.find(i);
            if(x == m_old2delegate.end())
                return nullptr;
            return x->second;
        }

        Tachyon*        _old(tachyon_k, uint64_t i) const
        {
            auto x = m_old2tachyon.find(i);
            if(x == m_old2tachyon.end())
                return nullptr;
            return x->second;
        }

        Thread*        _old(thread_k, uint64_t i) const
        {
            auto x = m_old2thread.find(i);
            if(x == m_old2thread.end())
                return nullptr;
            return x->second;
        }
        
        //  --------------------
        //  methods

        Reincarnator(const Save& save, const ReincarnationConfig& cfg, bool threading) : 
            m_save(save), m_config(cfg), m_threading(threading)
        {
        }
        
        
        //  --------------------
        //  builders

        std::error_code build()
        {
            std::error_code ec;
            for(auto& d : m_save.delegates.data){
                if(m_remap.contains(d.id))
                    return errors::duplicate_id();

                const DelegateMeta* dm  = dynamic_cast<const DelegateMeta*>(DelegateMeta::find(d.class_));
                if(!dm)
                    return errors::bad_delegate();

                delegate_t& dd  = m_delegates[d.id];
                dd.save     = &d;
                dd.delegate = static_cast<Delegate*>(dm->create());
                if(!dd.delegate)
                    return errors::bad_delegate();
                m_remap[d.id]    = dd.delegate->id();
                m_old2delegate[d.id] = dd.delegate.ptr();
            }
            
            for(auto& t : m_save.threads.data){
                if(m_remap.contains(t.id))
                    return errors::duplicate_id();

                const ThreadMeta*   tm = dynamic_cast<const ThreadMeta*>(ThreadMeta::find(t.class_));
                if(!tm) 
                    return errors::bad_thread();
                
                thread_t&   tt = m_threads[t.id];
                tt.save     = &t;
                tt.thread   = static_cast<Thread*>(tm -> create());
                if(!tt.thread)
                    return errors::bad_thread();
                m_remap[t.id]    = tt.thread->id();
                m_old2tachyon[t.id] = tt.thread.ptr();
                m_old2thread[t.id]  = tt.thread.ptr();
            }

            for(auto& t : m_save.tachyons.data){
                if(m_remap.contains(t.id))
                    return errors::duplicate_id();

                const TachyonMeta* tm = dynamic_cast<const TachyonMeta*>(TachyonMeta::find(t.class_));
                if(!tm)
                    return errors::bad_tachyon();
                tachyon_t&  tt  = m_tachyons[t.id];
                tt.save     = &t;
                tt.tachyon  = static_cast<Tachyon*>(tm -> create());
                if(!tt.tachyon)
                    return errors::bad_tachyon();
                m_remap[t.id]    = tt.tachyon->id();
                m_old2tachyon[t.id] = tt.tachyon.ptr();
            }
        
            for(auto& d : m_delegates){
                ec  = load(*d.second.delegate, *d.second.save);
                if(ec != std::error_code())
                    return ec;
            }

            for(auto& t : m_tachyons){
                ec  = load(*t.second.tachyon, *t.second.save);
                if(ec != std::error_code())
                    return ec;

            }

            for(auto& t : m_threads){
                ec  = load(*t.second.thread, *t.second.save);
                if(ec != std::error_code())
                    return ec;
            }

            return {};
        }

        void    extract(TachyonPtrVector& tachs)
        {
            tachs.reserve(m_tachyons.size());
            for(auto& itr : m_tachyons)
                tachs.push_back(itr.second.tachyon);
        }
        
        uint64_t remap(uint64_t i, bool preserve=false) const
        {
            auto x = m_remap.find(i);
            if(x == m_remap.end())
                return preserve ? i : 0ULL;
            return x->second;
        }
        
        std::error_code load(Object& obj, const ObjectSave& sv)
        {
            std::error_code ec;
            for(const PropertyMeta* p : obj.metaInfo().properties(ALL).all){
                if(!p->tagged(kTag_Save))
                    continue;
                
                auto x  = sv.properties.find(std::string(p->name()));
                if(x == sv.properties.end())
                    continue;
                
                if(p->tagged(kTag_TachyonID)){
                    if(auto v = std::get_if<uint64_t>(&x->second)){
                        if(p->type().id() == meta<TypedID>().id()){
                            Tachyon*    t   = _old(TACHYON, *v);
                            if(!t)
                                continue;
                            Any     val = Any::from(TypedID(*t));
                            p->set(&obj, val);
                            continue;
                        } else if(p->type().size() == sizeof(uint64_t)){
                            Any     val = Any(p->type(), (const void*) &*v);
                            p->set(&obj, val);
                            continue;
                        }
                        
                        return errors::todo();
                        
                        
                    } else
                        return errors::bad_property();
                } else {
                    if(auto v = std::get_if<Any>(&x->second)){
                        ec  = p->set(&obj, *v);
                        if(ec != std::error_code())
                            return ec;
                    } else
                        return errors::bad_property();
                }
            }
        
            return {};
        }

        std::error_code load(Delegate&d, const DelegateSave&sv)
        {
            // origin... 

            std::error_code ec = load(static_cast<Object&>(d), static_cast<const ObjectSave&>(sv));
            if(ec != std::error_code())
                return ec;
            return d.load(sv);
        }

        std::error_code load(Tachyon&t, const TachyonSave&sv, bool isThread=false)
        {
            // origin... 
            
            if(!isThread){
                if(sv.parent)
                    t.load_set_parent(_old(TACHYON, sv.parent));
                    
                for(uint64_t i : sv.children)
                    t.load_add_child(_old(TACHYON, i));
                
                bool    pushed  = false;
                
                if(auto p = std::get_if<uint64_t>(&sv.owner)){
                    uint64_t    thid    = remap(*p);
                    if(thid){
                        m_byThread[{thid}].push_back(&t);
                        pushed  = true;
                    }
                } else if(auto p = std::get_if<StdThread>(&sv.owner)){
                    m_stdThread[*p].push_back(&t);
                    pushed   = true;
                }
                
                if(!pushed)
                    m_byThread[{0}].push_back(&t);
            }
            
            t.load_set_template(sv.origin);
            
            std::error_code ec = load(static_cast<Object&>(t), static_cast<const ObjectSave&>(sv));
            if(ec != std::error_code())
                return ec;

            t.load_attributes(sv.uattrs);
            t.load_attributes(sv.pattrs);

            for(const ResourceProperty * r : t.metaInfo().resources(ALL).all){
                auto x = sv.resources.find(std::string(r->name()));
                if(x == sv.resources.end())
                    continue;
                    
                ResourceCPtr        res = Resource::resource_load({ &r->resource() }, x->second);
                if(!res)
                    return errors::bad_resource();
                r->set(&t, res);
            }

            for(const DelegateProperty* d : t.metaInfo().delegates(ALL).all){
                auto x = sv.delegates.find(std::string(d->name()));
                if(x == sv.delegates.end())
                    continue;
                Delegate* dg    = _old(DELEGATE, x->second);
                if(!dg)
                    continue;
                d -> set(&t, dg);
            }

            return t.load(sv);
        }

        std::error_code load(Thread&t, const ThreadSave&sv)
        {
            return load(static_cast<Tachyon&>(t), static_cast <const TachyonSave&>(sv));
        }
    };

    std::error_code Save::execute(TachyonPtrVector&tachs, const ReincarnationConfig&config) const
    {
        Reincarnator    exec(*this, config, false);
        
        std::error_code ec  = exec.build();
        if(ec != std::error_code())
            return ec;
        
        exec.extract(tachs);
        return {};
    }
    
    std::error_code Save::execute(schedule_k, const ReincarnationConfig&config, TachyonIDSet* pIDs) const
    {
        Reincarnator    exec(*this, config, true);
        std::error_code ec  = exec.build();
        if(ec != std::error_code())
            return ec;

        const Frame* frame  = Frame::current();
        if(!frame)
            return errors::null_frame();


        ThreadID        owner;
        if(auto p = std::get_if<StdThread>(&config.owner)){
            owner   =  Thread::standard(*p);
        } else if(auto p = std::get_if<ThreadID>(&config.owner)){
            owner   = *p;
        } else if(config.parent){
            owner   = frame->owner(config.parent);
        } else {
            owner   = Thread::current()->id();
        }
        if(!owner)
            return errors::null_owner();
        TypedID     ownerT( owner.id, Type::Thread);

        TachyonPtrVector    tachyons;
        exec.extract(tachyons);
        if(pIDs){
            for(auto & itr : exec.m_tachyons)
                pIDs->insert(itr.second.tachyon->id());
        }

        if(!exec.m_threads.empty()){
            Application* app    = Application::app();
            if(!app)
                return errors::null_application();
            for(auto& th : exec.m_threads)
                app->start_thread(th.second.thread);
        }
        
        for(auto& itr : exec.m_byThread){
            if(config.parent){
                for(TachyonPtr& tp : itr.second){
                    if(!tp->parent()){
                        tp->set_parent(config.parent);
                        tp->load_owner_allow_different_thread();
                    }
                }
            }
            
            if(!itr.first.id){ // this is to the owner
                Tachyon::mail(ownerT, new ScheduleCommand({.target=ownerT}, std::move(itr.second)));
            } else {
                TypedID tgt( itr.first.id, Type::Thread);
                Tachyon::mail(tgt, new ScheduleCommand({.target=tgt}, std::move(itr.second)));
            }
        }
        
        return {};
    }

    using remapper_t    = Map<uint64_t, uint64_t>;
    
    static void remap(save_value_t&sv, const remapper_t& rmap)
    {
        if(auto p = std::get_if<uint64_t>(&sv))
            sv  = rmap.get(*p, 0);
    }
    
    static void remap(ObjectSave&sv, const remapper_t& rmap)
    {
        for(auto& itr : sv.properties)
            remap(itr.second, rmap);
    }

    static void remap(StateSave&sv, const remapper_t& rmap)
    {
        for(auto& itr : sv.ustate)
            remap(itr.second, rmap);
        for(auto& itr : sv.pstate)
            remap(itr.second, rmap);
    }

    static void remap(DelegateSave&sv, const remapper_t& rmap)
    {
        remap((ObjectSave&) sv, rmap);
        remap((StateSave&) sv, rmap);
    }

    static void remap(TachyonSave&sv, const remapper_t& rmap)
    {
        remap((ObjectSave&) sv, rmap);
        remap((StateSave&) sv, rmap);
        sv.parent       = rmap.get(sv.parent, 0);
        for(auto& c : sv.children)
            c           = rmap.get(c, 0);
        for(auto& d : sv.delegates)
            d.second    = rmap.get(d.second);
        if(auto p = std::get_if<uint64_t>(&sv.owner))
            sv.owner    = rmap.get(*p, 0);
    }

    void    Save::renumerate()
    {
        Map<uint64_t, uint64_t>     remapper;
        uint64_t                    next    = 1;
        size_t                      index;
        
        index   = 0;
        delegates.byId.clear();
        for(auto& d : delegates.data){
            uint64_t id             = d.id;
            d.id                    = next++;
            delegates.byId[d.id]    = index++;
            remapper[id]            = d.id;
        }
        
        index   = 0;
        threads.byId.clear();
        for(auto& t : threads.data){
            uint64_t id             = t.id;
            t.id                    = next++;
            threads.byId[t.id]      = index++;
            remapper[id]            = t.id;
        }

        index   = 0;
        tachyons.byId.clear();
        for(auto& t : tachyons.data){
            uint64_t id             = t.id;
            t.id                    = next++;
            tachyons.byId[t.id]     = index++;
            remapper[id]            = t.id;
        }
        
        for(auto& d : delegates.data)
            remap(d, remapper);
        for(auto& t : tachyons.data)
            remap(t, remapper);
        for(auto& t : threads.data)
            remap(t, remapper);
    }
}
