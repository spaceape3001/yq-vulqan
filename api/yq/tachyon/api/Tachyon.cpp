////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tachyon.hpp"
#include "TachyonBind.hpp"
#include "TachyonData.hpp"
#include "TachyonInfoWriter.hpp"
#include "InterfaceInfo.hpp"
#include "Post.hpp"
#include "Proxy.hpp"

#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    TachyonBind::TachyonBind(const Tachyon*tc) : m_tachyon(tc ? tc -> id() : TachyonID{}) 
    {
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    
    TachyonSnap::TachyonSnap()
    {
    }
    
    TachyonSnap::~TachyonSnap()
    {
        for(Proxy* p : proxies)
            delete p;
        proxies.clear();
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    TachyonData::TachyonData()
    {
    }
    
    TachyonData::~TachyonData()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    TachyonInfo::TachyonInfo(std::string_view zName, MetaObjectInfo& base, const std::source_location& sl) :
        MetaObjectInfo(zName, base, sl)
    {
        set(Flag::TACHYON);
    }

    TachyonInfo::~TachyonInfo()
    {
    }

    void    TachyonInfo::add_dispatch(const PBXDispatch*pbx)
    {
        if(thread_safe_write()){
            m_dispatches.local.push_back(pbx);
        }
    }

    void    TachyonInfo::add_interface(const InterfaceInfo* ii)
    {
        if(thread_safe_write()){
            m_interfaces.local << ii;
        }
    }

    TachyonInfo::dispatch_span_t     TachyonInfo::dispatches(const PostInfo* pi) const
    {
        if(!pi)
            return {};
        auto i = m_dispatch.find(pi);
        if(i == m_dispatch.end())
            return {};
        return i->second;
    }

    void    TachyonInfo::sweep_impl() 
    {   
        MetaObjectInfo::sweep_impl();
        
        m_dispatch.clear();
        m_interfaces.all.clear();
        
        const TachyonInfo*  tibase = dynamic_cast<const TachyonInfo*>(base());
        if(tibase){
            m_dispatch          = tibase->m_dispatch;
            m_interfaces.all   += tibase->m_interfaces.all;
        }
        
        m_interfaces.all += m_interfaces.local;
    }

    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

    Tachyon::Tachyon(const Param& p) : Tachyon(p, INIT)
    {
        //  Add to thread...
    }
    
    Tachyon::Tachyon(const Param&p, init_t)
    {
        m_threadId  = thread::id();
    }

    Tachyon::Tachyon(const Param& p, thread_t) : Tachyon(p, INIT)
    {
    }

    Tachyon::~Tachyon()
    {
    }

    void        Tachyon::handle(const PostCPtr&pp)
    {
        
    }

    void        Tachyon::mail(forward_t, const PostCPtr& pp)
    {
        m_forward.push_back(pp);
    }

    void        Tachyon::mail(rx_t, const PostCPtr& pp)
    {
        if(advise(pp) == PostAdvice::Reject)
            return ;
        
        TXLOCK
        m_mailbox.push_back(pp);
    }

    void    Tachyon::mail(tx_t, const PostCPtr&pp)
    {
        m_outbox.push_back(pp);
    }

    Tachyon::PostAdvice  Tachyon::advise(const PostCPtr&pp) const 
    { 
        if(const TachyonBind* p = dynamic_cast<const TachyonBind*>(pp.ptr())){
            return (p -> tachyon() == id()) ? PostAdvice::Accept : PostAdvice::Reject;
        }
        return PostAdvice::None; 
    }
    
    bool Tachyon::in_thread() const
    {
        return m_threadId == thread::id();
    }

    void Tachyon::proxy(ProxyFN&& fn)
    {
        TXLOCK
        m_proxied.push_back(std::move(fn));
    }

    void Tachyon::proxy_me(std::function<void(Proxy*)>&& dst)
    {
        for(const InterfaceInfo* ii : metaInfo().interfaces().all){
            Proxy*  p   = ii->proxy(this);
            if(!p)
                continue;
            p->m_interface  = ii;
            p->m_tachyon    = this;
            p->m_revision   = revision();
            dst(p);
        }
    }

    TachyonDataPtr              Tachyon::tick(Context&)
    {
        TachyonDataPtr  data    = metaInfo().create_data();
        if(!data)
            return {};
        data.tick       = 
        return {};
    }
    
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

#if 0    
    void    Tachyon::forward(const post::PostCPtr&pp)
    {
        for(Dispatcher* p : m_forward)
            p -> receive(pp);
    }
#endif    

#if 0
    void    Tachyon::receive(const post::PostCPtr& pp) 
    {
        if(!pp)
            return ;
        
        if(m_replay && in_thread()){
            post::PBX::receive(pp);
            return;
        }
            
        if(const TachyonBind* p = dynamic_cast<const TachyonBind*>(pp.ptr())){
            if(p->tachyon() != this)
                return ;
        }

        switch(m_postMode){
        case PostMode::Direct:
            post::PBX::receive(pp);
            break;
        case PostMode::ThreadSafe:
            if(in_thread()){
                post::PBX::receive(pp);
            } else {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        case PostMode::Queued:
            if(in_thread()){
                m_direct.push_back(pp);
            } else {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        case PostMode::OneQueue:
            {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        }
    }

    void    Tachyon::_replay(direct_t)
    {
        std::vector<post::PostCPtr> posts;
        std::swap(posts, m_direct);
        for(const post::PostCPtr& p : posts)
            receive(p);
    }
    
    void    Tachyon::_replay(thread_t)
    {
        std::vector<post::PostCPtr> posts;
        {
            XLOCK
            std::swap(posts, m_threaded);
        }
        for(const post::PostCPtr& p : posts)
            receive(p);
    }

    bool    Tachyon::in_replay() const
    {
        return in_thread() && m_replay;
    }
    
    void    Tachyon::replay(direct_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(DIRECT);
        m_replay  = false;
    }

    void    Tachyon::replay(thread_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(THREAD);
        m_replay  = false;
    }
    
    void    Tachyon::replay(all_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(DIRECT);
        _replay(THREAD);
        m_replay  = false;
    }

    void    Tachyon::set_post_mode(PostMode pm)
    {
        m_postMode      = pm;
    }
#endif

    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon abstract base class");
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tachyon)
