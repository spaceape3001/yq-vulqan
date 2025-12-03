////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Save.hpp"
#include <yq/tags.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Delegate.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/meta/DelegateProperty.hpp>
#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <yq/tachyon/io/Builder.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Save)

namespace yq::tachyon {
    namespace {
        void    export_object(ObjectSave& sv, const Object& obj)
        {
            sv.type     = std::string(obj.metaInfo().name());
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
            sv.parent   = tac.parent();

            if(!ss.flags(SaveFlag::SkipOwnership)){
                ThreadID    owner   = tac.owner();
                auto x = threads.find(owner);
                if(x != threads.end()){
                    sv.owner    = x->second;
                } else if(owner)
                    sv.owner    = owner;
            }
            
            for(auto& ch : tac.children())
                sv.children.push_back(ch);
            
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

    void    Save::init_meta()
    {
        auto w  = writer<Save>();
        w.description("Tachyon Save");
        w.property("type", &Save::type).tag({kTag_Log});
    }
}
