////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Context.hpp"
#include "Frame.hpp"
#include "InterfaceInfo.hpp"
#include "Post.hpp"
#include "Tachyon.hpp"
#include "TachyonBind.hpp"
#include "TachyonData.hpp"
#include "TachyonInfoWriter.hpp"

#include <yq/core/ThreadId.hpp>
#include <yq/command/TachyonSetParentCommand.hpp>

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


    Tachyon::Tachyon(const Param& cfg)
    {
        m_thread    = thread::id();
        
        TachyonID   parent;
        if(auto p = std::get_if<Tachyon*>(&cfg.parent)){
            Tachyon*    t   = *p;
            if(t){
                parent    = t->id();
            }
        }

        if(auto p = std::get_if<TachyonID>(&cfg.parent)){
            parent  = *p;
        }
        
        if(parent){
            m_inbox.push_back(new TachyonSetParentCommand(parent));
        }
    }
    
    Tachyon::~Tachyon()
    {
    }


    Tachyon::PostAdviceFlags  Tachyon::advise(const Post& pp) const
    {
        return {} 
    }

    std::span<const TachyonID>      Tachyon::children() const 
    { 
        return m_children; 
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

    bool Tachyon::in_thread() const
    {
        return m_thread == thread::id();
    }

    void    Tachyon::mail(children_t, const PostCPtr&pp)
    {
        if(!pp)
            return;
        if(!m_data)
            return;
        if(!in_thread())
            return;
        m_data -> post.children.push_back(pp);
    }

    void        Tachyon::mail(forward_t, const PostCPtr& pp)
    {
        if(!pp)
            return ;
        if(!m_data)
            return;
        if(!in_thread())
            return;
        m_data->post.forward.push_back(pp);
    }

    void    Tachyon::mail(parent_t, const PostCPtr&pp)
    {
        if(!pp)
            return ;
        if(!m_data)
            return;
        if(!in_thread())
            return;
        m_data->post.parent.push_back(pp);
    }

    void        Tachyon::mail(rx_t, const PostCPtr& pp)
    {
        if(!pp)
            return ;
            
        TWLOCK
        m_inbox.push_back(pp);
    }

    void    Tachyon::mail(rx_t, std::span<PostCPtr const> pp)
    {
        TWLOCK
        m_inbox.insert(m_post.inbox.end(), pp.begin(), pp.end());
    }

    void    Tachyon::mail(tx_t, const PostCPtr&pp)
    {
        if(!m_data)
            continue;
        if(!m_data)
            return;
        if(!in_thread())
            return;
        m_data->post.sent.push_back(pp);
    }

    void        Tachyon::mark()
    {
        m_dirty    = true;
    }

    void    Tachyon::reset(thread_t)
    {
        m_wthread   = kInvalidThread;
    }

    void Tachyon::snap(TachyonSnap&snap) const
    {
        for(const InterfaceInfo* ii : metaInfo().interfaces().all){
            Proxy*  p   = ii->proxy(this);
            if(!p)
                continue;
                
            p->m_interface  = ii;
            p->m_tachyon    = this;
            p->m_revision   = m_revision;
            snap.proxies.push_back(p);
        }
    }

    std::pair<TachyonDataPtr, TachyonSnapPtr>      Tachyon::tick(thread_t, zero_t)
    {
        TachyonDataPtr  data    = metaInfo().create_data();
        m_thread    = thread::id();
        m_data      = data.ptr();

        data->owner             = m_owner;
        
    }

    std::pair<TachyonDataPtr, TachyonSnapPtr>      Tachyon::tick(thread_t, Context&ctx)
    {
        TachyonDataPtr  data    = metaInfo().create_data();

        m_thread    = thread::id();
        m_data      = data.ptr();
        
        data->tick              = ctx.tick;
        data->owner             = m_owner;

        {
            TXLOCK
            std::swap(data->post.received, m_inbox);
        }
        
        if(!data->received.empty()){
            for(TachyonID sn : m_snoops){
                tx(ctx.frame, sn, data->post.received);
            }
        }
        
        for(const PostCPtr& pp : data->post.received){
            if(!pp)
                continue;
            PostAdviceFlags paf = advise(*pp);
            if(paf(PostAdvice::Reject))
                continue;
            if(paf(PostAdvice::Forward))
                data->post.forward.push_back();
            if(paf(PostAdvice::Parent))
                data->post.parent.push_back();
            if(paf(PostAdvice::Children))
                data->post.children.push_back();
            data->post.accepted.push_back(pp);
            dispatch(pp);
        }
        
        {
            TXLOCK
            std::swap(data->post.forward, m_post.forward);
        }

        if(!data->post.forward.empty()){
            for(TachyonID fwd : m_forward){
                tx(ctx.frame, fwd, data->post.forward);
            }
        }
        
        tick();
        
        if(!data->post.outbox.empty()){
            for(TachyonID sub : m_subscriber){
                tx(ctx.frame, sub, data->post.outbox);
            }
        }
        
        if(!data->post.children.empty()){
            for(TachyonID ch : m_children){
                tx(ctx.frame, ch, data->post.children);
            }
        }
        
        if(m_parent && !data->post.parent.empty()){
            tx(ctx.frame, m_parent, data->post.parent);
        }
        
        if(m_dirty || !m_snap || (m_snap->revision != m_revision)){
            m_snap              = metaInfo().create_snap(this);
            m_snap -> time      = ctx.time;
            m_snap -> revision  = ++m_revision;
            m_dirty             = false;
        }
        
        m_thread    = kInvalidThread;
        m_data      = nullptr;
        return { data, m_snap };
    }

    void Tachyon::tx(const Frame& frame, TachyonID tid, std::span<const PostCPtr> posts)
    {
        Tachyon* t  = frame.object(tid);
        if(!t)
            return ;
        t->mail(RX, posts);
    }

    void Tachyon::unhandled(const PostCPtr&)
    {
        //  Default does nothing
    }
}
