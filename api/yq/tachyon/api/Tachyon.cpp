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
#include "Thread.hpp"

#include <yq/tachyon/commands/TachyonProxyCommand.hpp>
#include <yq/tachyon/commands/TachyonThreadCommand.hpp>

#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/logging.hpp>

namespace yq::tachyon {

    struct Mail;

    bool unspecified(const PostAdvice& pa)
    {
        return static_cast<bool>(std::get_if<std::monostate>(&pa));
    }

// ------------------------------------------------------------------------

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


    void Tachyon::retain(TachyonPtr tp)
    {
        Thread::retain(tp);
    }
    
    void Tachyon::retain(TachyonPtr tp, ThreadID tid)
    {
        Thread::retain(tp, tid);
    }

// ------------------------------------------------------------------------


    Tachyon::Tachyon(const Param& p) : Tachyon(INIT, p)
    {
        //  Add us to the current thread
    }
    
    Tachyon::Tachyon(init_t, const Param& p) 
    {
        _name(p.name);
    }
    
    Tachyon::Tachyon(thread_t, const Param& p) : Tachyon(INIT, p)
    {
    }

    Tachyon::~Tachyon()
    {
    }

    void    Tachyon::_add_child(TypedID tid)
    {
        m_children.push_back(tid);
        _subscribe(tid, MG::Children);
        
        // TODO: SEND EVENT HERE
    }
    
    void    Tachyon::_add_snoop(TachyonID tid)
    {
        m_snoop.push_back(tid);
    }

    void    Tachyon::_del_child(TachyonID tid)
    {
        TypedID child = {};
        
        size_t cnt = std::erase_if(m_children, [&](const TypedID& a) -> bool { 
            if(a.id == tid.id){
                child   = a;
                return true;
            } else {
                return false;
            }
        });
        if(cnt){
            _unsubscribe(tid, MG::Children);
        
            // TODO: SEND EVENT HERE
        }
    }
    
    void    Tachyon::_del_snoop(TachyonID tid)
    {
        std::erase(m_snoop, tid);
    }

    bool    Tachyon::_has_child(TachyonID tid) const 
    {
        for(const TypedID& c : m_children){
            if(c.id == tid.id)
                return true;
        }
        return false;
    }

    bool    Tachyon::_name(name_spec ns, OldNameFN cap)
    {
        auto clear = [&]() -> bool {
            if(m_name.empty())
                return false;
            if(cap)
                cap(std::move(m_name));
            m_name  = {};
            return true;
        };
        
        auto set = [&](std::string&& nv) -> bool {
            if(nv == m_name)
                return false;
            if(cap)
                cap(std::move(m_name));
            m_name  = std::move(nv);
            return true;
        };
        
        if(std::get_if<std::monostate>(&ns))
            return clear();
        
        if(auto p = std::get_if<const char*>(&ns)){
            const char* z   = *p;
            if(!z || !*z)
                return clear();
            return set(z);
        }
        
        if(auto p = std::get_if<std::string_view>(&ns)){
            std::string_view    z   = *p;
            if(z.empty())
                return clear();
            return set(std::string(z));
        }
        
        if(auto p = std::get_if<std::string>(&ns)){
            std::string&    z   = *p;
            if(z.empty())
                return clear();
            return set(std::move(z));
        }
        
        return false;
    }

    void    Tachyon::_set_parent(TypedID tid)
    {
        if(tid == m_parent)
            return ;
            
        _unsubscribe(m_parent, MG::Parent);
        m_parent    = tid;
        if(tid){
            _subscribe(tid, MG::Parent);
        }
        
        
        //  TODO: SEND EVENT HERE
    }
    
    void    Tachyon::_subscribe(TachyonID tid, MGF mgf)
    {
        m_listeners[tid] |= mgf;
    }

    void    Tachyon::_unsubscribe(TachyonID tid, MGF mgf)
    {
        auto i = m_listeners.find(tid);
        if(i != m_listeners.end()){
            i->second -= mgf;
            if(!i->second){
                m_listeners.erase(i);
            }
        }
    }
    
    PostAdvice  Tachyon::advise(const Post& pp) const
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
            std::swap(messages,         m_inbox);
            std::swap(data->outbound,   m_outbox);
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
                    data->outbound.push_back({mgf, pp});
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
            if(auto p = std::get_if<MG>(&out.to)){
                for(auto& i : m_listeners){
                    if(i.second(*p)){
                        tx(i.first, out.post);
                    }
                }
            }
            
            if(auto p = std::get_if<MGF>(&out.to)){
                for(auto& i : m_listeners){
                    if((i.second & *p) != MGF{}){
                        tx(i.first, out.post);
                    }
                }
            }
            
            if(auto p = std::get_if<TachyonID>(&out.to)){
                tx(*p, out.post);
            }
        }

        //////////////////////////////////
        //  SNAPSHOT
        
        if(m_dirty || !m_snap || (m_snap->revision != m_revision)){
            TachyonSnapPtr  snap    = metaInfo().create_snap(this);
            snap -> time            = ctx.time;
            snap -> revision        = ++m_revision;
            m_snap                  = snap.ptr();
            m_dirty                 = false;
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
        if(!in_tick()){
            tachyonCritical << ident() << "::frame() -- not in tick!  Owner is " << (uint64_t) m_owner 
                << " though current is " << (uint64_t) Thread::current()->id();
        }
        assert(in_tick());
        return m_context->frame;
    }

    Tachyon::Ident               Tachyon::ident() const
    {
        return { metaInfo().name(), (uint64_t) id() };
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

    void    Tachyon::on_thread_command(const TachyonThreadCommand& cmd)
    {
        if(cmd.tachyon() != id())
            return ;
        Thread::rethread(this, cmd.thread());
    }

    void    Tachyon::owner(push_t, ThreadID tid)
    {
        mail(new TachyonThreadCommand(this, tid));
    }

    void    Tachyon::send(const PostCPtr&pp, PostTarget to)
    {
        if(!pp)
            return;
        if(in_tick()){
            m_data->outbound.push_back({to, pp});
        } else {
            TXLOCK
            m_outbox.push_back({to, pp});
        }
    }

    void Tachyon::slot_proxy_command(const TachyonProxyCommand& cmd)
    {
        if(cmd.tachyon() == id()){
            cmd.function()();
        }
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

    // ---- INFO AT THE END ---
    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon Object");
        w.slot(&Tachyon::slot_proxy_command);
        w.slot(&Tachyon::on_thread_command);
        w.property("name", &Tachyon::name);
    }
}

std::ostringstream& operator<<(std::ostringstream&str, const yq::tachyon::Tachyon::Ident& i)
{
    str << "{" << i.metaName << ":" << i.id << "}";
    return str;
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Tachyon)
