////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "InterfaceInfo.hpp"
#include "Post.hpp"
#include "Tachyon.hpp"
#include "TachyonBind.hpp"
#include "TachyonData.hpp"
#include "TachyonInfoWriter.hpp"

#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    static constexpr const unsigned int kInvalidThread   = ~0;

    class Context;

    struct Tachyon::Impl {
        using mutex_t       = tbb::spin_rw_mutex;
        using lock_t        = mutex_t::scoped_lock;
        
        using control_hash_t    = std::multimap<uint32_t, TachyonID>;
    
        const uint64_t          id;

        mutable mutex_t         mutex;          // used for guards
        std::vector<PostCPtr>   inbox;          //< Inbox (under mutex guard)
        std::vector<ProxyFN>    proxied;        //< Setters (under mutex guard)
        std::vector<PostCPtr>   outbox;
        std::vector<PostCPtr>   forward;
        std::vector<TachyonID>  snoops;         //!< Those eavesdropping on us
        std::vector<TachyonID>  forwards;       //!< Those we'll forward (conditionally)
        std::vector<TachyonID>  subscribers;    //!< Who we're broadcasting to
        control_hash_t          control;
        ThreadID                thread;
        uint64_t                revision        = 0;
        bool                    dirty           = false;
        
        ThreadData*             tick_data       = nullptr;
        Context*                tick_context    = nullptr;
        unsigned int            wthread         = kInvalidThread;
        
        Impl(uint64_t i) : id(i) {};
    };

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


    Tachyon::Tachyon(const Param&, ImplCreator&& impl) : m( impl ? impl(UniqueID::id()) : new Impl(UniqueID::id()))
    {
    }
    
    Tachyon::~Tachyon()
    {
    }

    Tachyon::Impl&               Tachyon::_impl()
    {
        return *m.get();
    }
    
    const Tachyon::Impl&         Tachyon::_impl() const
    {
        return *m.get();
    }

    Tachyon::PostAdvice  Tachyon::advise(const Post& pp) const
    {
        if(const TachyonBind* p = dynamic_cast<const TachyonBind*>(&pp)){
            return (p -> tachyon() == id()) ? PostAdvice::Accept : PostAdvice::Reject;
        }
        return PostAdvice::None; 
    }

    void    Tachyon::handle(const PostCPtr&pp)
    {
        if(!pp)
            return ;
        
        for(const PBXDispatch* fn : metaInfo().dispatches(&pp->metaInfo())){
            if(fn->dispatch(this, pp))
                break;
        }
    }

    bool Tachyon::in_thread() const
    {
        return m->wthread == thread::id();
    }


    void        Tachyon::mail(forward_t, const PostCPtr& pp)
    {
        m->forward.push_back(pp);
    }

    void        Tachyon::mail(rx_t, const PostCPtr& pp)
    {
        if(!pp)
            return ;
            
        if(advise(*pp) == PostAdvice::Reject)
            return ;
        
        Impl::lock_t    _lock(m->mutex, true);
        m->inbox.push_back(pp);
    }

    void    Tachyon::mail(tx_t, const PostCPtr&pp)
    {
        m->outbox.push_back(pp);
    }

    void        Tachyon::mark()
    {
        m->dirty    = true;
    }

    void Tachyon::proxy(ProxyFN&& fn)
    {
        Impl::lock_t    _lock(m->mutex, true);
        m->proxied.push_back(std::move(fn));
    }

    void Tachyon::proxy_me(std::vector<Proxy*>&dst) 
    {
        for(const InterfaceInfo* ii : metaInfo().interfaces().all){
            Proxy*  p   = ii->proxy(this);
            if(!p)
                continue;
            p->m_interface  = ii;
            p->m_tachyon    = this;
            p->m_revision   = m->revision;
            dst.push_back(p);
        }
    }
}
