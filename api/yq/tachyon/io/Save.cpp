////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yq/tags.hpp>
#include <yq/core/Any.hpp>
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
#include <yq/tachyon/io/Builder.hpp>

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
        using invalid_id_property   = error_db::entry<"Bad ID property">;
        using null_application      = error_db::entry<"Application not found">;
        using null_frame            = error_db::entry<"Requested frame not found">;
        using null_owner            = error_db::entry<"Requested owner not found">;
        using null_parent           = error_db::entry<"Requested parent not found">;
    }

    namespace {
        void    export_object(ObjectSave& sv, const Object& obj)
        {
            sv.type     = std::string(obj.metaInfo().name());
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
                    sv.idprops[std::string(p->name())] = tid;
                } else {
                    sv.properties[std::string(p->name())] = std::move(*val);
                }
            }
        }

        void    export_delegate(DelegateSave& sv, const Delegate& dlg)
        {
            export_object(sv, dlg);
            sv.id      = dlg.id();
            dlg.save(sv);
        }

        void    export_tachyon(TachyonSave& sv, Save& ss, const Tachyon& tac, bool isThread=false)
        {
            static const StdThreadRevMap threads  = Thread::standard_thread_reverse_map();

            export_object(sv, tac);
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
            
            tac.save(sv);
        }

        void    export_thread(ThreadSave& sv, Save& ss, const Thread& th)
        {
            export_tachyon(sv, ss, th, true);
            th.save(sv);
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
        export_delegate(ret, dlg);
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
        if(const Thread*p = dynamic_cast<const Thread*>(&obj)){
            _thread(*p);
        } else if(const Tachyon*p = dynamic_cast<const Tachyon*>(&obj)){
            _tachyon(*p);
        } else if(const Delegate*p = dynamic_cast<const Delegate*>(&obj)){
            _delegate(*p);
        }
    
        return *this;
    }

    size_t  Save::data_size() const 
    {
        return 0; // TODO
    }

    //////////////////////////////////////
    struct Save::Reincarnator {
        //  --------------------
        // structures
        struct delegate_t {
            const DelegateSave*     save    = nullptr;
            DelegateCPtr            delegate;
        };
        
        struct tachyon_t {
            const TachyonSave*      save    = nullptr;
            TachyonPtr              tachyon;
            bool                    nullpar = false;
        };
        
        struct thread_t {
            const ThreadSave*       save    = nullptr;
            ThreadPtr               thread;
            TachyonPtrVector        tachyons;
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
            return errors::todo();
        }

        void    extract(TachyonPtrVector& tachs)
        {
            tachs.reserve(m_tachyons.size());
            for(auto& itr : m_tachyons)
                tachs.push_back(itr.second.tachyon);
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
