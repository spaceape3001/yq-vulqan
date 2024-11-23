////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Context.hpp"
#include "Frame.hpp"
#include "InterfaceInfo.hpp"
#include "Post.hpp"
#include "Proxy.hpp"
#include "Tachyon.hpp"
#include "TachyonBind.hpp"
#include "TachyonData.hpp"
#include "TachyonInfoWriter.hpp"

#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    struct Mail;

    TachyonBind::TachyonBind(const Tachyon*v ) : m_tachyon(v ? v->id() : TachyonID{})
    {
    }

// ------------------------------------------------------------------------

    TachyonData::TachyonData()
    {
    }
    
    TachyonData::~TachyonData()
    {
    }


// ------------------------------------------------------------------------


    TachyonInfo::TachyonInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::TACHYON);
    }

    TachyonInfo::~TachyonInfo()
    {
    }

    void    TachyonInfo::set(Type t)
    {
        m_types |= t;
    }

    void    TachyonInfo::add_dispatch(const PBXDispatch*pbx)
    {
        if(thread_safe_write()){
            m_dispatches.defined.push_back(pbx);
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
    
    struct PBXEntry {
        unsigned            depth   = 0;
        const PostInfo*     info    = nullptr;
        const PBXDispatch*  fn      = nullptr;
        
        bool operator<(const PBXEntry& b) const
        {
            if(info != b.info)
                return info < b.info;
            return depth < b.depth;
        }
    };
    
    static void     _add(std::vector<PBXEntry>&ranked, const PBXDispatch* fn, unsigned int depth)
    {
        const PostInfo* ppi = fn->post();
        assert(ppi);
        ranked.push_back({depth, ppi, fn});
        for(const ObjectInfo* derv : ppi->deriveds(true).all){
            const PostInfo* ppd = static_cast<const PostInfo*>(derv);   // should *NEVER* be wrong given the inheritance
            if(!ppd->is_abstract()){
                ranked.push_back({depth, ppd, fn});
            }
        }
    }

    void    TachyonInfo::sweep_impl() 
    {   
        ObjectInfo::sweep_impl();
        
        m_dispatch.clear();
        m_dispatches.ranked.clear();
        m_interfaces.all.clear();
        
        std::vector<PBXEntry>   ranked;
        
        for(const PBXDispatch* fn : m_dispatches.defined){
            _add(ranked, fn, 0);
        }
        
        const TachyonInfo*  tibase = dynamic_cast<const TachyonInfo*>(base());
        if(tibase){
            m_interfaces.all   += tibase->m_interfaces.all;
            
            unsigned int depth  = 1;
            
            for(; tibase; tibase = dynamic_cast<const TachyonInfo*>(tibase->base())){
                for(const PBXDispatch* fn : tibase->m_dispatches.defined){
                    _add(ranked, fn, depth);
                }
            }
        }
        
        m_interfaces.all += m_interfaces.local;

        if(!ranked.empty()){
            std::stable_sort(ranked.begin(), ranked.end());
            m_dispatches.ranked.resize(ranked.size(), nullptr);

            const PostInfo* pi  = nullptr;
            size_t          nC  = 0;
            
            for(size_t n=0;n<ranked.size();++n){
                const PBXEntry& r = ranked[n];
                if(pi != r.info){   // edge detection
                    if(pi){
                        m_dispatch[pi]    = std::span(&m_dispatches.ranked[nC], n-nC);
                        nC  = n;
                    }
                    pi  = r.info;
                }
                
                m_dispatches.ranked[n]   = r.fn;
            }
            
            m_dispatch[pi] = std::span(&m_dispatches.ranked[nC], ranked.size()-nC);
        }
    }


// ------------------------------------------------------------------------

    TachyonSnap::TachyonSnap()
    {
    }
    
    TachyonSnap::~TachyonSnap()
    {
        for(Proxy* p : proxies)
            delete p;
        proxies.clear();
    }

// ------------------------------------------------------------------------

    bool Tachyon::accepting(const PostAdvice& pa)
    {
        return std::get_if<accept_t>(&pa) || std::get_if<MG>(&pa) || std::get_if<MGF>(&pa);
    }

    MGF  Tachyon::groups(const PostAdvice&pa)
    {
        if(auto p = std::get_if<MG>(&pa)){
            return *p;
        }
        if(auto p = std::get_if<MGF>(&pa)){
            return *p;
        }
        return {};
    }
    
    bool Tachyon::rejecting(const PostAdvice&pa)
    {
        return static_cast<bool>(std::get_if<reject_t>(&pa));
    }

    bool Tachyon::unspecified(const PostAdvice&pa) 
    {
        return static_cast<bool>(std::get_if<std::monostate>(&pa));
    }

    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon Object");
    }

// ------------------------------------------------------------------------


    Tachyon::Tachyon(const Param& p) : Tachyon(INIT, p)
    {
        //  Add us to the current thread
    }
    
    Tachyon::Tachyon(init_t, const Param& p) 
    {
    }
    
    Tachyon::Tachyon(thread_t, const Param& p) : Tachyon(INIT, p)
    {
    }

    Tachyon::~Tachyon()
    {
    }

    Tachyon::PostAdvice  Tachyon::advise(const Post& pp) const
    {
        return {};
    }

    Context&        Tachyon::context() const
    {
        assert(in_tick());
        return const_cast<Context&>(*m_context);
    }

    Tachyon::Result      Tachyon::cycle(Context&ctx)
    {
        //////////////////////////////////
        //  START THE CYCLE
    
        TachyonDataPtr  data    = metaInfo().create_data();
        m_thread        = thread::id();
        m_data          = data.ptr();
        m_context       = &ctx;
        data->owner     = m_owner;
        data->tick      = ctx.tick;

        //////////////////////////////////
        //  CHECK INBOUND MESSAGES

        std::vector<PostCPtr>       messages;

        {
            TXLOCK
            std::swap(messages, m_inbox);
        }
        
        if(!messages.empty()){
            for(TachyonID sn : m_snoop){
                tx(sn, messages);
            }
            
            data->inbound.reserve(messages.size());

            for(const PostCPtr& pp : messages){
                if(!pp)
                    continue;
                
                PostAdvice pa = advise(*pp);
                if(rejecting(pa)){
                    data->inbound.push_back({ pp, InPost::State::Rejected });
                    continue;
                }
                
                data->inbound.push_back({pp, InPost::State::Accepted });
                MGF mgf = groups(pa);
                if(mgf != MGF{}){
                    data->outbound.push_back({pp, mgf});
                }
                dispatch(pp);
            }
        }
        
        //////////////////////////////////
        //  TICK
        
        Execution ex    = tick(ctx);

        //////////////////////////////////
        //  OUTBOUND MESSAGES
        
        for(auto& out : data->outbound){
            for(auto& i : m_listeners){
                if((i.second & out.groups) != MGF{}){
                    tx(i.first, out.post);
                }
            }
        }

        //////////////////////////////////
        //  SNAPSHOT
        
        if(m_dirty || !m_snap || (m_snap->revision != m_revision)){
            TachyonSnapPtr  snap    = metaInfo().create_snap(this);
            snap -> time        = ctx.time;
            snap -> revision    = ++m_revision;
            m_snap              = snap.ptr();
            m_dirty             = false;
        }
        
        //////////////////////////////////
        //  END THE CYCLE

        m_thread    = kInvalidThread;
        m_data      = nullptr;
        m_context   = nullptr;
        
        //////////////////////////////////
        //  RETURN
        
        return { data, m_snap, ex };
    }

    TachyonData&    Tachyon::data()
    {
        assert(in_tick());
        return *m_data;
    }
    
    void    Tachyon::dispatch(const PostCPtr& pp)
    {
        if(!pp)
            return ;

        for(const PBXDispatch* fn : metaInfo().dispatches(&pp->metaInfo())){
            if(fn->dispatch(this, pp))
                return ;
        }

        unhandled(pp);
    }

    const Frame&  Tachyon::frame() const
    {
        assert(in_tick());
        return m_context->frame;
    }

    bool Tachyon::in_tick() const
    {
        return m_thread == thread::id();
    }

    void        Tachyon::mail(const PostCPtr& pp)
    {
        if(!pp)
            return ;
            
        TXLOCK
        m_inbox.push_back(pp);
    }

    void    Tachyon::mail(std::span<PostCPtr const> pp)
    {
        TXLOCK
        m_inbox.insert(m_inbox.end(), pp.begin(), pp.end());
    }

    void        Tachyon::mark()
    {
        m_dirty    = true;
    }

    ThreadID    Tachyon::owner() const 
    { 
        TRLOCK
        return m_owner; 
    }

    void    Tachyon::send(const PostCPtr&pp, MGF mgf)
    {
        if(!pp)
            return;
        if(!in_tick())
            return;
        m_data->outbound.push_back({pp, mgf});
    }

    void Tachyon::snap(TachyonSnap&snap) const
    {
        for(const InterfaceInfo* ii : metaInfo().interfaces().all){
            Proxy*  p   = ii->proxy(const_cast<Tachyon*>(this));
            if(!p)
                continue;
                
            p->m_interface  = ii;
            p->m_tachyon    = const_cast<Tachyon*>(this);
            p->m_revision   = m_revision;
            snap.proxies.push_back(p);
        }
    }

    void        Tachyon::subscribe(TachyonID tid, MGF grp)
    {
        m_listeners[tid] |= grp;
    }
    

    Execution   Tachyon::tick(Context&)
    {
        return {};
    }

    void Tachyon::tx(TachyonID tid, PostCPtr pp)
    {
        assert(m_context);
        Tachyon* t  = m_context->frame.object(tid);
        if(!t)
            return ;
        t->mail(pp);
    }

    void Tachyon::tx(TachyonID tid, std::span<const PostCPtr> posts)
    {
        assert(m_context);
        Tachyon* t  = m_context->frame.object(tid);
        if(!t)
            return ;
        t->mail(posts);
    }

    void Tachyon::unhandled(const PostCPtr&)
    {
        //  Default does nothing
    }

    void        Tachyon::unsubscribe(TachyonID tid, MGF grp)
    {
        if((m_listeners[tid] -= grp) == MGF{}){
            m_listeners.erase(tid);
        }
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Tachyon)
