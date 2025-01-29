////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Context.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/InterfaceInfo.hpp>
#include <yt/api/Proxy.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/TachyonBind.hpp>
#include <yt/api/TachyonData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/api/Thread.hpp>

#include <yt/msg/Post.hpp>

#include <ya/commands/sim/PauseCommand.hpp>
#include <ya/commands/sim/ResumeCommand.hpp>
#include <ya/commands/tachyon/DestroyCommand.hpp>
//#include <ya/commands/tachyonProxyCommand.hpp>
#include <ya/commands/tachyon/RethreadCommand.hpp>
#include <ya/commands/tachyon/SnoopCommand.hpp>
#include <ya/commands/tachyon/SubscribeCommand.hpp>
#include <ya/commands/tachyon/UnsnoopCommand.hpp>
#include <ya/commands/tachyon/UnsubscribeCommand.hpp>

#include <ya/events/sim/PauseEvent.hpp>
#include <ya/events/sim/ResumeEvent.hpp>
#include <ya/events/tachyon/DestroyEvent.hpp>
#include <ya/events/tachyon/DirtyEvent.hpp>

#include <yq/core/StreamOps.hpp>
#include <yq/core/ThreadId.hpp>
#include <yt/logging.hpp>

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

    TachyonBind::TachyonBind(TypedID v) : m_tachyon(v.id)
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
        return std::get_if<accept_k>(&pa) || std::get_if<MG>(&pa) || std::get_if<MGF>(&pa);
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
        return static_cast<bool>(std::get_if<reject_k>(&pa));
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
    
    Tachyon::Tachyon(init_k, const Param& p) 
    {
        _name(p.name);
    }
    
    Tachyon::Tachyon(thread_k, const Param& p) : Tachyon(INIT, p)
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
            
        if(m_parent)
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
    
    bool            Tachyon::children_started() const
    {
        const Frame*    curFrame    = Frame::current();
        if(!curFrame)
            return false;
            
        for(const TypedID& t : m_children){
            const TachyonSnap*  ts  = curFrame->snap(TachyonID(t.id));
            if(!ts)
                return false;
            if(!ts->started)
                return false;
        }
        
        return true;
    }

    const Context&  Tachyon::context() const
    {
        assert(in_tick());
        return *m_context;
    }

    Tachyon::Result      Tachyon::cycle(const Context&ctx)
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
        
        Context     ctx2(ctx);
        Execution   ex = tiktok(ctx2);

        //////////////////////////////////
        //  OUTBOUND MESSAGES
        
        #if 0
        // check for "dirty" behavior -- DISABLED, UNSURE IF I WANT THIS
        if(m_snap && (m_dirty || (m_snap->revision != m_revision))){
            data->outbound.push_back(new DirtyEvent({.source=this}));
        }
        #endif
        
        for(auto& out : data->outbound){
            if(std::get_if<target_k>(&out.to) && out.post->target()){
                tx(out.post->target().tachyonID(), out.post);
            }
        
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
            TachyonSnapPtr  snap    = metaInfo().create_snap(*this);
            snap -> time            = ctx.time;
            snap -> revision        = ++m_revision;
            m_snap                  = snap.ptr();
            m_dirty                 = false;
        }
        
        metaInfo().finalize_data(*this, *m_data);
        
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

    bool            Tachyon::dying() const
    {
        return m_stage >= Stage::Teardown;
    }

    void            Tachyon::finalize(TachyonData&) const
    {
    }

    TypedID             Tachyon::id(typed_k) const
    {
        return TypedID(*this);
    }

    Tachyon::Ident               Tachyon::ident() const
    {
        return { metaInfo().name(), m_name, (uint64_t) id() };
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

    void    Tachyon::on_destroy_event(const DestroyEvent& evt)
    {
        std::erase(m_children, evt.source());
    }

    ThreadID    Tachyon::owner() const 
    { 
        TRLOCK
        return m_owner; 
    }

    void    Tachyon::on_destroy_command(const DestroyCommand&cmd)
    {
        if(cmd.target() != id())
            return ;

        if(m_stage < Stage::Teardown)
            stage_teardown();
    }

    void    Tachyon::on_pause_command(const PauseCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_stage != Stage::Running)
            return;
        stage_paused();
    }
    
    void    Tachyon::on_resume_command(const ResumeCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_stage != Stage::Paused)
            return;
        stage_resume();
    }

    void    Tachyon::on_rethread_command(const RethreadCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        Thread::rethread(this, cmd.thread());
    }

    void    Tachyon::on_snoop_command(const SnoopCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(std::find(m_snoop.begin(), m_snoop.end(), cmd.listener()) != m_snoop.end())
            return ;
        m_snoop.push_back(cmd.listener());
    }

    void    Tachyon::on_subscribe_command(const SubscribeCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        subscribe(cmd.listener(), cmd.groups());
    }

    void    Tachyon::on_unsubscribe_command(const UnsubscribeCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        unsubscribe(cmd.listener(), cmd.groups());
    }

    void    Tachyon::on_unsnoop_command(const UnsnoopCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        std::erase(m_snoop, cmd.listener());
    }

    void    Tachyon::owner(push_k, ThreadID tid)
    {
        mail(new RethreadCommand({.target=*this}, tid));
    }

    bool    Tachyon::paused() const
    {
        return m_stage == Stage::Paused;
    }

    Execution    Tachyon::paused(const Context&)
    {
        return {};
    }

    bool    Tachyon::running() const
    {
        return m_stage == Stage::Running;
    }

    void    Tachyon::send(const PostCPtr&pp, PostTarget to)
    {
        if(!pp)
            return;
        if(!pp->source()){
            const_cast<Post*>(pp.ptr()) -> m_source = TypedID(*this);
        }
        
        if(in_tick()){
            m_data->outbound.push_back({to, pp});
        } else {
            TXLOCK
            m_outbox.push_back({to, pp});
        }
    }

    Execution    Tachyon::setup(const Context&)
    {
        return {};
    }

    void Tachyon::snap(TachyonSnap&snap) const
    {
        snap.parent     = m_parent;
        snap.self       = this;
        snap.children   = m_children;
        snap.started    = m_stage > Stage::Setup;
        snap.running    = m_stage == Stage::Running;
        snap.paused     = m_stage == Stage::Paused;
        snap.teardown   = m_stage >= Stage::Teardown;
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


    void Tachyon::stage_kaput()
    {
        m_stage     = Stage::Kaput;
        m_cycle     = 0;

        if(!m_children.empty()){
            for(TypedID c : m_children){
                send(new DestroyCommand({.source=*this, .target=c}));
            }
        }
    }

    void    Tachyon::stage_paused()
    {
        m_stage = Stage::Paused;
        m_cycle = 0;
        send(new PauseEvent({.source=*this}));
        mark();
    }

    
    void    Tachyon::stage_resume()
    {
        m_stage = Stage::Running;
        m_cycle = 0;
        send(new ResumeEvent({.source=*this}));
        mark();
    }

    void    Tachyon::stage_running()
    {
        m_stage = Stage::Running;
        m_cycle = 0;
        mark();
    }
    
    void Tachyon::stage_teardown()
    {
        m_stage     = Stage::Teardown;
        m_cycle     = 0;
        mark();
    }

    bool        Tachyon::starting() const
    {
        return m_stage <= Stage::Setup;
    }

    void        Tachyon::subscribe(TachyonID tid, MGF grp)
    {
        m_listeners[tid] |= grp;
    }

    void         Tachyon::teardown()
    {
        mail(new DestroyCommand({.target=*this}));
    }

    Execution    Tachyon::teardown(const Context&)
    {
        return {};
    }
    
    Execution   Tachyon::tick(const Context&)
    {
        return {};
    }

    bool    Tachyon::tick_cycle(const Context&) 
    {
        if(!m_cycle)        // first one ALWAYS goes through
            return true;
        return true;
    }

    Execution   Tachyon::tiktok(const Context&ctx)
    {
        
            /*
                Yes, there will be some evil goto's here to help cleanup 
                the execution result handling.  While the extra routines
                (startup & shutdown) help organize up the various 
                implementations, it dirties up this "what-to-do" response.
                To avoid complexity of lambdas, extra "helper" routines
                to clutter up the logic, we're going with the goto instead.
            */

        Execution   ex;
        switch(m_stage){
        case Stage::Preinit:
            goto jSetup;
        case Stage::Setup:
            if(!tick_cycle(ctx))
                goto jDone;
            ex      = setup(ctx);
            ++m_cycle;
            if(std::get_if<std::monostate>(&ex)){
                ex  = ALWAYS;
                if(!children_started())
                    goto jDone;
                goto jRun;
            }
            if(auto p = std::get_if<bool>(&ex)){
                if(*p){
                    ex  = ALWAYS;
                    if(!children_started())
                        goto jDone;
                    goto jRun;
                } else 
                    goto jKaput;
            }
            if(std::get_if<accept_k>(&ex)){
                if(!children_started())
                    goto jDone;
                goto jRun;
            }
            if(auto p = std::get_if<std::error_code>(&ex)){
                if(*p == std::error_code()){
                    ex  = ALWAYS;
                    if(!children_started())
                        goto jDone;
                    goto jRun;
                } else {
                    goto jKaput;
                }
            }
            if(std::get_if<error_k>(&ex))
                goto jKaput;
            if(std::get_if<abort_k>(&ex))
                goto jKaput;
            if(std::get_if<start_k>(&ex)){
                ex  = ALWAYS;
                if(!children_started())
                    goto jDone;
                goto jRun;
            }
            if(std::get_if<teardown_k>(&ex))
                goto jTeardown;
                
            if(std::get_if<delete_k>(&ex))
                goto jKaput;
            if(std::get_if<wait_k>(&ex)){
                ex  = ALWAYS;
                goto jDone;
            }
            if(std::get_if<continue_k>(&ex)){
                ex  = ALWAYS;
                goto jDone;
            }
            if(std::get_if<pause_k>(&ex)){
                ex  = ALWAYS;
                goto jPause;
            }
            if(std::get_if<resume_k>(&ex)){
                if(!children_started())
                    goto jDone;
                ex  = ALWAYS;
                goto jRun;
            }
            
            if(is_ticking(ex)){
                if(!children_started())
                    goto jDone;
                goto jRun;
            }

            //  shouldn't really hit here... still, treat it as "wait"
            break;

        case Stage::Running:

            if(!tick_cycle(ctx))
                goto jDone;

            ex      = tick(ctx);
            ++m_cycle;
            
            if(std::get_if<std::monostate>(&ex))
                goto jDone;
            
            if(std::get_if<accept_k>(&ex))
                goto jDone;

            if(auto p = std::get_if<bool>(&ex)){
                if(*p){
                    goto jDone;
                } else {
                    goto jError;
                }
            }
            
            if(auto p = std::get_if<std::error_code>(&ex)){
                if(*p == std::error_code()){
                    goto jDone;
                } else {
                    goto jError;
                }
            }
            
            if(std::get_if<error_k>(&ex))
                goto jError;
            if(std::get_if<abort_k>(&ex))
                goto jError;
            
            if(std::get_if<start_k>(&ex))
                goto jDone;
            if(std::get_if<teardown_k>(&ex))
                goto jTeardown;
            if(std::get_if<delete_k>(&ex))
                goto jKaput;
            if(std::get_if<wait_k>(&ex))
                goto jDone;
            if(std::get_if<continue_k>(&ex))
                goto jDone;
            if(std::get_if<pause_k>(&ex))
                goto jPause;
            break;
            
        case Stage::Paused:

            if(!tick_cycle(ctx))
                goto jDone;

            ex      = paused(ctx);
            ++m_cycle;
            if(std::get_if<std::monostate>(&ex))
                goto jDone;
                
            if(auto p = std::get_if<bool>(&ex)){
                if(*p){
                    goto jResume;
                } else {
                    goto jDone;
                }
            }
            
            if(std::get_if<accept_k>(&ex))
                goto jDone;
            if(std::get_if<std::error_code>(&ex))
                goto jDone;
            if(std::get_if<error_k>(&ex))
                goto jDone;
            if(std::get_if<abort_k>(&ex))
                goto jDone;
            if(std::get_if<teardown_k>(&ex))
                goto jTeardown;
            if(std::get_if<delete_k>(&ex))
                goto jKaput;
            if(std::get_if<wait_k>(&ex))
                goto jDone;
            if(std::get_if<continue_k>(&ex))
                goto jDone;
            if(std::get_if<pause_k>(&ex))
                goto jDone;
            if(std::get_if<resume_k>(&ex))
                goto jResume;
            if(is_ticking(ex))
                goto jResume;
            break;
        case Stage::Teardown:
            if(!tick_cycle(ctx))
                goto jDone;
                
            ex      = teardown(ctx);
            ++m_cycle;
            if(std::get_if<std::monostate>(&ex))
                goto jKaput;
            if(auto p = std::get_if<bool>(&ex)){
                if(*p){
                    goto jKaput;
                } else {
                    goto jDone;
                }
            }
            
            if(std::get_if<accept_k>(&ex))
                goto jKaput;
            if(std::get_if<std::error_code>(&ex))
                goto jKaput;
            if(std::get_if<error_k>(&ex))
                goto jKaput;
            if(std::get_if<abort_k>(&ex))
                goto jKaput;
            if(std::get_if<start_k>(&ex))   // technically a logic error
                goto jKaput;
            if(std::get_if<teardown_k>(&ex))
                goto jKaput;
            if(std::get_if<delete_k>(&ex))
                goto jKaput;
                
            if(std::get_if<wait_k>(&ex))
                goto jDone;
            if(std::get_if<continue_k>(&ex))
                goto jDone;

            if(std::get_if<pause_k>(&ex))
                goto jKaput;
            if(std::get_if<resume_k>(&ex))
                goto jKaput;
            if(is_ticking(ex))
                goto jDone;
            break;
        case Stage::Kaput:
            ++m_cycle;
            if(!m_children.empty())
                goto jDone;
            goto jDelete;
        }
        
        goto jDone;


    jSetup:
        m_stage     = Stage::Setup;
        m_cycle     = 0;
        mark();
        goto jDone;
        
    jError:
    jPause:
        stage_paused();
        goto jDone;
            
    jResume:
        stage_resume();
        goto jDone;
        
    jRun:
        stage_running();
        goto jDone;
        
    jTeardown:
        stage_teardown();
        goto jDone;

    jKaput:
        stage_kaput();
        goto jDone;
        
    jDelete:
        send(new DestroyEvent({.source=*this}), MGF({ MG::Parent, MG::General }));
        ex          = DELETE;
            
    jDone:
        return ex;
    }

    void Tachyon::tx(TachyonID tid, PostCPtr pp)
    {
        const Frame*  curFrame = Frame::current();
        assert(curFrame);
        if(!curFrame)
            return ;
    
        Tachyon* t  = curFrame->object(tid);
        if(!t)
            return ;
        t->mail(pp);
    }

    void Tachyon::tx(TachyonID tid, std::span<const PostCPtr> posts)
    {
        const Frame*  curFrame = Frame::current();
        assert(curFrame);
        if(!curFrame)
            return ;

        Tachyon* t  = curFrame->object(tid);
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

    // ---- TACHYON HELPER
    
    Tachyon::Helper::Helper()
    {
    }
    
    Tachyon::Helper::~Helper()
    {
    }
    
    TypedID         Tachyon::Helper::typed() const
    {
        const Tachyon*t   = dynamic_cast<const Tachyon*>(this);
        if(t){
            return TypedID(t);
        } else {
            return {};
        }
    }

    void            Tachyon::Helper::mark()
    {
        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t)
            t->mark();
    }

    void            Tachyon::Helper::send(PostCPtr pp, PostTarget tgt)
    {
        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t)
            t->send(pp, tgt);
    }
    
    void            Tachyon::Helper::mail(PostCPtr pp)
    {
        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t)
            t->mail(pp);
    }

    // ---- INFO AT THE END ---
    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon Object");
        w.slot(&Tachyon::on_destroy_command);
        w.slot(&Tachyon::on_destroy_event);
        w.slot(&Tachyon::on_pause_command);
        w.slot(&Tachyon::on_resume_command);
        w.slot(&Tachyon::on_rethread_command);
        w.slot(&Tachyon::on_snoop_command);
        w.slot(&Tachyon::on_subscribe_command);
        w.slot(&Tachyon::on_unsnoop_command);
        w.slot(&Tachyon::on_unsubscribe_command);
        w.property("name", &Tachyon::name);
    }


    Stream& operator<<(Stream&str, const Tachyon::Ident& i)
    {
        str << "{" << i.metaName << ":" << i.id;
        if(!i.tacName.empty()){
            str<<":\"" << i.tacName << "\"";
        }
        str << "}";
        return str;
    }
}

std::ostringstream& operator<<(std::ostringstream&str, const yq::tachyon::Tachyon::Ident& i)
{
    str << "{" << i.metaName << ":" << i.id;
    if(!i.tacName.empty()){
        str<<":\"" << i.tacName << "\"";
    }
    str << "}";
    return str;
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Tachyon)
