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

    struct Tachyon::Tick {
        time_point_t        start;
        ThreadData*         data    = nullptr;
        unsigned int        thread  = 0;
    };

        //! Read-only lock, conditional to object's thread
        #define TRLOCK                                          \
            tbb::spin_rw_mutex::scoped_lock    _lock;           \
            if(!in_thread())                                    \
                _lock.acquire(m_mutex, false);

        //! Write lock, conditional to object's thread
        #define TWLOCK                                          \
            tbb::spin_rw_mutex::scoped_lock    _lock;           \
            if(!in_thread())                                    \
                _lock.acquire(m_mutex, true);
        
        //! Write lock, unconditional
        #define TXLOCK tbb::spin_rw_mutex::scoped_lock  _lock(m_mutex, true);


    struct Tachyon::Impl {
        mutable tbb::spin_rw_mutex          mutex;
        std::vector<PostCPtr>               inbox;        //!< Inbound (under mutex guard)
        std::vector<ProxyFN>                proxied;      //!< Inbound proxy changes (under mutex guard)
        std::vector<PostCPtr>               outbox;       //!< Outbound
        std::vector<PostCPtr>               forward;      //!< Forwarding posts
        std::vector<TachyonID>              snoops;       //!< Those eavesdropping on us
        std::vector<TachyonID>              forwards;     //!< Those we'll forward (conditionally)
        std::vector<TachyonID>              subscribers;  //!< Who we're broadcasting to
        std::multimap<uint32_t, TachyonID>  control;      //!< Those controlling us
        ThreadID                            thread;
        uint64_t                            revision    = 1;
        bool                                dirty       = false;
        
        //  TICK CONTROL
        Tick                                tick;
    };

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
        ObjectInfo(zName, base, sl)
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

    Tachyon::Tachyon(const Param& p) : Tachyon(p, INIT), m(new Impl)
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

    Tachyon::PostAdvice  Tachyon::advise(const PostCPtr&pp) const 
    { 
        if(const TachyonBind* p = dynamic_cast<const TachyonBind*>(pp.ptr())){
            return (p -> tachyon() == id()) ? PostAdvice::Accept : PostAdvice::Reject;
        }
        return PostAdvice::None; 
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
        m_inbox.push_back(pp);
    }

    void    Tachyon::mail(tx_t, const PostCPtr&pp)
    {
        m_outbox.push_back(pp);
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

    TachyonDataPtr      Tachyon::_tick_create()
    {
        TachyonDataPtr  data    = metaInfo().create_data();
        if(!data)
            return {};
        m_data  = data.ptr();
        return data;
    }

    TachyonDataPtr              Tachyon::tick(Context&ctx)
    {
        
        m_dirty             = false;
        m_threadId          = thread::id();
            
        std::vector<ProxyFN>    proxied;
        {
            TXLOCK
            std::swap(data->received, m_inbox);
            std::swap(proxied, m_proxied);
        }
        
        
        //  Not sure to the order...
        for(const PostCPtr& p : data->received){
        }
        
        for(ProxyFN&& fn : proxied){
            fn();
        }
        proxied.clear();
        
        data.tick       = ctx.tick;
        
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
