////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/InterfaceMeta.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/api/Thread.hpp>

#include <yq/tachyon/api/Post.hpp>

#include <yq/tachyon/command/sim/PauseCommand.hpp>
#include <yq/tachyon/command/sim/ResumeCommand.hpp>
#include <yq/tachyon/command/tachyon/AddChildCommand.hpp>
#include <yq/tachyon/command/tachyon/DestroyCommand.hpp>
//#include <yq/tachyon/command/tachyonProxyCommand.hpp>
#include <yq/tachyon/command/tachyon/RemoveChildCommand.hpp>
#include <yq/tachyon/command/tachyon/RethreadCommand.hpp>
#include <yq/tachyon/command/tachyon/SetAttributeCommand.hpp>
#include <yq/tachyon/command/tachyon/SetNameCommand.hpp>
#include <yq/tachyon/command/tachyon/SetParentCommand.hpp>
#include <yq/tachyon/command/tachyon/SnoopCommand.hpp>
#include <yq/tachyon/command/tachyon/SubscribeCommand.hpp>
#include <yq/tachyon/command/tachyon/UnsnoopCommand.hpp>
#include <yq/tachyon/command/tachyon/UnsubscribeCommand.hpp>

#include <yq/tachyon/event/sim/PauseEvent.hpp>
#include <yq/tachyon/event/sim/ResumeEvent.hpp>
#include <yq/tachyon/event/tachyon/ChildAddEvent.hpp>
#include <yq/tachyon/event/tachyon/ChildRemoveEvent.hpp>
#include <yq/tachyon/event/tachyon/DestroyEvent.hpp>
#include <yq/tachyon/event/tachyon/DirtyEvent.hpp>
#include <yq/tachyon/event/tachyon/NameChangeEvent.hpp>
#include <yq/tachyon/event/tachyon/ParentChangeEvent.hpp>

#include <yq/core/Any.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/stream/Text.hpp>
#include <yq/meta/Init.hpp>

#include <cassert>

#define TACHYON_HELPER_MAIL_REPORT_FAILURE  1

namespace yq::tachyon {

    struct Mail;

    bool unspecified(const PostAdvice& pa)
    {
        return static_cast<bool>(std::get_if<std::monostate>(&pa));
    }

// ------------------------------------------------------------------------

    TachyonData::TachyonData()
    {
    }
    
    TachyonData::~TachyonData()
    {
    }


// ------------------------------------------------------------------------


    struct TachyonMeta::Repo {
        std::vector<const TachyonMeta*> all;
    };

    TachyonMeta::Repo& TachyonMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const TachyonMeta*>&    TachyonMeta::all()
    {
        return repo().all;
    }

    TachyonMeta::TachyonMeta(std::string_view zName, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(zName, base, sl)
    {
        set(Flag::TACHYON);
        repo().all.push_back(this);
    }

    TachyonMeta::~TachyonMeta()
    {
        assert(false && "NOTHING IS SUPPOSED TO TRIGGER THIS!");
    }

    void    TachyonMeta::set(Type t)
    {
        m_types |= t;
    }

    void    TachyonMeta::add_dispatch(const PBXDispatch*pbx)
    {
        if(thread_safe_write()){
            m_dispatches.defined.push_back(pbx);
        }
    }

    void    TachyonMeta::add_interface(const InterfaceMeta* ii)
    {
        if(thread_safe_write()){
            m_interfaces.local << ii;
        }
    }

    const ResourceProperty*                TachyonMeta::resource(std::string_view sv) const
    {
        return m_resources.all.find(sv);
    }

    const MetaLookup<ResourceProperty>&    TachyonMeta::resources(bool all) const
    {
        return all ? m_resources.all : m_resources.local;
    }

    const DelegateProperty*             TachyonMeta::delegate(std::string_view sv) const
    {
        return m_delegates.all.find(sv);
    }

    const MetaLookup<DelegateProperty>&    TachyonMeta::delegates(bool all) const
    {
        return all ? m_delegates.all : m_delegates.local;
    }

    TachyonMeta::dispatch_span_t     TachyonMeta::dispatches(const PostMeta* pi) const
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
        const PostMeta*     info    = nullptr;
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
        const PostMeta* ppi = fn->post();
        assert(ppi);
        ranked.push_back({depth, ppi, fn});
        for(const ObjectMeta* derv : ppi->deriveds(ALL).all){
            const PostMeta* ppd = static_cast<const PostMeta*>(derv);   // should *NEVER* be wrong given the inheritance
            //if(!ppd->is_abstract()){
                ranked.push_back({depth, ppd, fn});
            //}
        }
    }

    const MetaLookup<InterfaceMeta>&    TachyonMeta::interfaces(bool all) const
    {
        return all ? m_interfaces.all : m_interfaces.local;
    }

    void    TachyonMeta::sweep_impl() 
    {   
        ObjectMeta::sweep_impl();

        if(this == &meta<Tachyon>())
            PostMeta::sweep_all();

        m_dispatch.clear();
        m_dispatches.ranked.clear();
        m_interfaces.all.clear();
        m_delegates.all.clear();
        m_resources.all.clear();
        
        std::vector<PBXEntry>   ranked;
        
        for(const PBXDispatch* fn : m_dispatches.defined){
            _add(ranked, fn, 0);
        }

        m_interfaces.all += m_interfaces.local;
        m_resources.all += m_resources.local;
        m_delegates.all += m_delegates.local;
        
        const TachyonMeta*  tibase = dynamic_cast<const TachyonMeta*>(base());
        if(tibase){
            m_interfaces.all   += tibase->m_interfaces.all;
            m_resources.all += tibase->m_resources.all;
            m_delegates.all += tibase->m_delegates.all;
            
            unsigned int depth  = 1;
            
            for(; tibase; tibase = dynamic_cast<const TachyonMeta*>(tibase->base())){
                for(const PBXDispatch* fn : tibase->m_dispatches.defined){
                    _add(ranked, fn, depth);
                }
            }
        }
        

        if(!ranked.empty()){
            std::stable_sort(ranked.begin(), ranked.end());
            m_dispatches.ranked.resize(ranked.size(), nullptr);

            const PostMeta* pi  = nullptr;
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
            
            if(pi){
                m_dispatch[pi] = std::span(&m_dispatches.ranked[nC], ranked.size()-nC);
            }
        }
    }

    void    TachyonMeta::report(Stream& out) const
    {
        out << "Report for TachyonMeta[" << name() << "]\n";
        out << "    ID              : " << id() << "\n";
        out << "    Description     : " << description() << "\n";
        out << "    Base            : " << base()->name() << "\n";

        out << "  BASES\n";
        for(const ObjectMeta* obj : bases(ALL).all){
            out << "    " << obj->name() << "\n";
        }
        
        out << "  DERIVES\n";
        for(const ObjectMeta* obj : deriveds(ALL).all){
            out << "    " << obj->name() << "\n";
        }

        out << "  DISPATCHES\n";
        for(auto& i : m_dispatch){
            out << "    " << i.first->name() << " -> " << i.second.size() << "\n";
        }

        out << "  INTERFACES\n";
        for(const InterfaceMeta* i : m_interfaces.all.all){
            out << "    " << i->name() << "\n";
        }

        out << "  METHODS\n";
        for(const MethodMeta* obj : methods(ALL).all){
            out << "    " << obj->name() << "\n";
        }

        out << "  PROPERTIES\n";
        for(const PropertyMeta* prop : properties(ALL).all){
            out << "    " << prop->name() << "\n";
        }
    }
    
    void    TachyonMeta::report(const char* cat, LogPriority pri) const
    {
        std::string     text;
        {
        
            stream::Text  out(text);
            report(out);
        }
        log_category(cat).getStream(log4cpp_priority(pri)) << text;
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

    void Tachyon::mail(StdThread tid, const PostCPtr&pp)
    {
        mail(Thread::standard(tid), pp);
    }
    
    void Tachyon::mail(TachyonID tid, const PostCPtr&pp)
    {
        if(!pp)
            return ;
            
        const Frame* frame  = Frame::current();
        if(!frame)
            return;
        Tachyon*  tac  = frame->object(tid);
        if(!tac)
            return ;
        tac -> mail(pp);
    }

    bool Tachyon::rejecting(const PostAdvice&pa)
    {
        return static_cast<bool>(std::get_if<reject_k>(&pa));
    }

    void Tachyon::retain(TachyonPtr tp)
    {
        Thread::retain(tp);
    }
    
    void Tachyon::retain(TachyonPtr tp, ThreadID tid)
    {
        Thread::retain(tp, tid);
    }

    void Tachyon::retain(TachyonPtr tp, StdThread st)
    {
        Thread::retain(tp, st);
    }

    bool Tachyon::unspecified(const PostAdvice&pa) 
    {
        return static_cast<bool>(std::get_if<std::monostate>(&pa));
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
        send(new ChildAddEvent({.source=*this}, tid));
        mark();
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
            send(new ChildRemoveEvent({.source=*this}, child));
            mark();
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

    Any     Tachyon::attribute(uint32_t k) const
    {
        auto i = m_progAttrs.find(k);
        if(i != m_progAttrs.end())
            return i->second;
        return Any();
    }
    
    Any     Tachyon::attribute(const std::string& k) const
    {
        auto i = m_userAttrs.find(k);
        if(i != m_userAttrs.end())
            return i->second;
        return Any();
    }
    
    bool    Tachyon::check_parent_thread()
    {
        if(!m_parent)
            return true;
            
        const Frame*    curFrame    = Frame::current();
        if(!curFrame)
            return false;
        const TachyonData*   parData = curFrame->data(m_parent);
        if(!parData)
            return false;
        if((parData -> owner != m_owner) && !m_flags(F::DifferentThread)){
            Thread::rethread(this, parData->owner);
            return false;
        }
        return true;
    }
    
    bool            Tachyon::children_started()
    {
        const Frame*    curFrame    = Frame::current();
        if(!curFrame)
            return false;
        
        bool    ret    = true;
        
        for(const TypedID& t : m_children){
            bool  okay  = false;
            do {
                const TachyonSnap*  ts  = curFrame->snap(TachyonID(t.id));
                if(!ts)
                    break;

                if(!ts->started)
                    break;

                Tachyon*  tac = curFrame->object(TachyonID(t.id));
                if(!tac)
                    break;

                const TachyonData*  td  = curFrame->data(TachyonID(t.id));
                if(!td)         // shouldn't ever fire
                    break;
                    
                if((td->owner != m_owner) && !tac->m_flags(F::DifferentThread)){
                    tac->mail(new RethreadCommand({.target = *tac}, m_owner));
                    break;
                }
                
                okay    = true;
            } while(false);
            if(!okay)
                ret = false;
        }
        
        return ret;
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
        
        time_point_t t0 = clock_t::now();
        
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
        
        auto ls = m_last.span(ALL);
        std::set<uint64_t>  seen(ls.begin(), ls.end());
        
        if(!messages.empty()){
            for(TachyonID sn : m_snoop){
                tx(sn, messages);
            }
            
            data->inbound.reserve(messages.size());

            for(const PostCPtr& pp : messages){
                if(!pp)
                    continue;
                
                m_last << pp->id();
                if(!seen.insert(pp->id()).second){   // we've already seen it...
                    data->inbound.push_back({ pp, InPost::State::Duplicate });
                    continue;
                }
                
                PostAdvice pa = advise(*pp);
                if(rejecting(pa)){
                    data->inbound.push_back({ pp, InPost::State::Rejected });
                    continue;
                }
                
                
                data->inbound.push_back({pp, InPost::State::Accepted });

                if(auto p = std::get_if<TachyonID>(&pa)){
                    data->outbound.push_back({*p, pp});
                } 
                
                if(auto p = std::get_if<StdThread>(&pa)){
                    data->outbound.push_back({*p, pp});
                } 

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
            std::set<TachyonID> sent;
            if(out.post->target()){
                tx(out.post->target().tachyonID(), out.post);
                sent.insert(out.post->target().tachyonID());
            }
        
            if(auto p = std::get_if<MG>(&out.to)){
                for(auto& i : m_listeners){
                    if(i.second(*p)){
                        if(sent.insert(i.first).second){
                            tx(i.first, out.post);
                        }
                    }
                }
            }
            
            if(auto p = std::get_if<MGF>(&out.to)){
                for(auto& i : m_listeners){
                    if((i.second & *p) != MGF{}){
                        if(sent.insert(i.first).second){
                            tx(i.first, out.post);
                        }
                    }
                }
            }
            
            if(auto p = std::get_if<TachyonID>(&out.to)){
                if(sent.insert(*p).second){
                    tx(*p, out.post);
                }
            }
            
            if(auto p = std::get_if<StdThread>(&out.to)){
                ThreadID    tid = Thread::standard(*p);
                if(sent.insert(tid).second){
                    tx(tid, out.post);
                }
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
        
        time_point_t t1 = clock_t::now();
        m_data -> cycleTime = unit::Nanosecond{ duration_nanoseconds_t(t1-t0).count() };


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

    bool                Tachyon::has_attribute(uint32_t k) const
    {
        return m_progAttrs.contains(k);
    }
    
    bool                Tachyon::has_attribute(const std::string& k) const
    {
        return m_userAttrs.contains(k);
    }

    TypedID             Tachyon::id(typed_k) const
    {
        return TypedID(*this);
    }

    Tachyon::Ident               Tachyon::ident() const
    {
        return { metaInfo().name(), m_name, (uint64_t) id() };
    }

    void Tachyon::info_log_post(const Post& p) const
    {
        tachyonInfo << "Post {" << p.metaInfo().name() << ":" << p.id() << "} Received by " << ident();
    }

    bool Tachyon::in_tick() const
    {
        return m_thread == thread::id();
    }

    bool Tachyon::kaput() const
    {
        return m_stage == Stage::Kaput;
    }

    void    Tachyon::load_add_child(TypedID tid)
    {
        m_children.push_back(tid);
        _subscribe(tid, MG::Children);
    }

    void  Tachyon::load_attributes(const AttrIDMMap& attrs)
    {
        m_progAttrs = attrs;
    }
    
    void  Tachyon::load_attributes(AttrIDMMap&& attrs)
    {
        m_progAttrs = std::move(attrs);
    }

    void  Tachyon::load_attributes(const AttrKeyMMap& attrs)
    {
        m_userAttrs = attrs;
    }

    void  Tachyon::load_attributes(AttrKeyMMap&& attrs)
    {
        m_userAttrs = std::move(attrs);
    }

    void    Tachyon::load_owner_allow_different_thread()
    {
        m_flags |= F::DifferentThread;
    }

    void    Tachyon::load_set_parent(TypedID tid)
    {
        m_parent    = tid;
        _subscribe(tid, MG::Parent);
    }

    void    Tachyon::load_set_template(const template_t& t)
    {
        m_template  = t;
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

    void    Tachyon::on_add_child_command(const AddChildCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        TypedID child   = Frame::resolve(cmd.child());
        if(!child)
            return ;
        _add_child(child);
    }

    void    Tachyon::on_destroy_event(const DestroyEvent& evt)
    {
        std::erase(m_children, evt.source());
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
    
    void    Tachyon::on_remove_child_command(const RemoveChildCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        TypedID child   = Frame::resolve(cmd.child());
        if(!child)
            return ;
        _del_child(child);
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

        if(cmd.thread() != m_owner)
            Thread::rethread(this, cmd.thread());
    }

    void    Tachyon::on_set_attribute_command(const SetAttributeCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(auto p = std::get_if<uint32_t>(&cmd.key()))
            m_progAttrs[*p] = cmd.value();
        if(auto p = std::get_if<std::string>(&cmd.key()))
            m_userAttrs[*p] = cmd.value();
    }

    void    Tachyon::on_set_name_command(const SetNameCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        if(cmd.name() == m_name)
            return;
    
        std::string old = cmd.name();
        std::swap(old, m_name);

        send(new NameChangeEvent({.source=*this}, std::move(old), m_name));
        mark();
    }

    void    Tachyon::on_set_parent_command(const SetParentCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
            
        TypedID par = Frame::resolve(cmd.parent());
        if(par == m_parent)
            return ;
            
        TypedID old = m_parent;
        
        if(m_parent){
            _unsubscribe(m_parent, MG::Parent);
            send(new RemoveChildCommand({.source=*this, .target=m_parent}, id(TYPED)), TARGET);
        }
        
        m_parent    = par;
        if(m_parent){
            _subscribe(m_parent, MG::Parent);
            send(new AddChildCommand({.source=*this, .target=m_parent}, id(TYPED)), TARGET);
        }
        
        send(new ParentChangeEvent({.source=*this}, old, par));
        mark();
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

    ThreadID    Tachyon::owner() const 
    { 
        TRLOCK
        return m_owner; 
    }

    void    Tachyon::owner(push_k, ThreadID tid)
    {
        m_flags |= F::DifferentThread;
        mail(new RethreadCommand({.target=*this}, tid));
    }

    void    Tachyon::owner(push_k, StdThread st)
    {
        owner(PUSH, Thread::standard(st));
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

#if 0
    void  Tachyon::set_attribute(uint32_t k, const Any& v)
    {
        mail(new SetAttributeCommand({.target=*this}, k, v));
    }
    
    void  Tachyon::set_attribute(std::string_view k, const Any&v)
    {
        mail(new SetAttributeCommand({.target=*this}, std::string(k), v));
    }
#endif

    void Tachyon::set_name(std::string_view k)
    {
        mail(new SetNameCommand({.target=*this}, std::string(k)));
    }

    void  Tachyon::set_parent(TachyonSpec tid)
    {
        mail(new SetParentCommand({.target=*this}, Frame::resolve(tid)));
    }

    Execution  Tachyon::setup(const Context&)
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
        snap.name       = m_name;
        
        //snap.userattrs  = m_userAttrs;
        //snap.progattrs  = m_progAttrs;
        
        for(const InterfaceMeta* ii : metaInfo().interfaces(ALL).all){
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
                goto jStart;
            }
            if(auto p = std::get_if<bool>(&ex)){
                if(*p){
                    ex  = ALWAYS;
                    goto jStart;
                } else 
                    goto jKaput;
            }
            if(std::get_if<accept_k>(&ex)){
                goto jStart;
            }
            if(auto p = std::get_if<std::error_code>(&ex)){
                if(*p == std::error_code()){
                    ex  = ALWAYS;
                    goto jStart;
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
                goto jStart;
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
                ex  = ALWAYS;
                goto jStart;
            }
            
            if(is_ticking(ex))
                goto jStart;

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
        
    jStart:
        if(!children_started())
            goto jDone;
        if(!check_parent_thread())
            goto jDone;
        goto jRun;
        
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
        #if 0
        if(tid == id()){
            mail(pp);
            return ;
        }
        #endif
            
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

    TypedID             Tachyon::typed_id() const
    {
        return TypedID(*this);
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
        if(!pp)
            return;
    
        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t){
            t->send(pp, tgt);
        } else {
            #if TACHYON_HELPER_MAIL_REPORT_FAILURE
            tachyonInfo << "Helper unable to send {" << pp->metaInfo().name() << ":" << pp->id() << "} due to not getting the tachyon";
            #endif
        }
    }
    
    void            Tachyon::Helper::mail(PostCPtr pp)
    {
        if(!pp)
            return;

        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t){
            t->mail(pp);
        } else {
            #if TACHYON_HELPER_MAIL_REPORT_FAILURE
            tachyonInfo << "Helper unable to mail {" << pp->metaInfo().name() << ":" << pp->id() << "} due to not getting the tachyon";
            #endif
        }
    }

    // ---- TACHYON IDENT

    void Tachyon::Ident::write(std::ostringstream& str) const
    {
        str << "{" << metaName << ":" << id;
        if(!tacName.empty()){
            str<<":\"" << tacName << "\"";
        }
        str << "}";
    }

    void Tachyon::Ident::write(log4cpp::CategoryStream& str) const
    {
        str << "{" << metaName << ":" << id;
        if(!tacName.empty()){
            str<<":\"" << tacName << "\"";
        }
        str << "}";
    }

    void Tachyon::Ident::write(Stream& str) const
    {
        str << "{" << metaName << ":" << id;
        if(!tacName.empty()){
            str<<":\"" << tacName << "\"";
        }
        str << "}";
    }

    // ---- INFO AT THE END ---
    void Tachyon::init_meta()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon Object");
        w.slot(&Tachyon::on_add_child_command);
        w.slot(&Tachyon::on_destroy_command);
        w.slot(&Tachyon::on_destroy_event);
        w.slot(&Tachyon::on_pause_command);
        w.slot(&Tachyon::on_remove_child_command);
        w.slot(&Tachyon::on_resume_command);
        w.slot(&Tachyon::on_rethread_command);
        w.slot(&Tachyon::on_set_attribute_command);
        w.slot(&Tachyon::on_set_name_command);
        w.slot(&Tachyon::on_set_parent_command);
        w.slot(&Tachyon::on_snoop_command);
        w.slot(&Tachyon::on_subscribe_command);
        w.slot(&Tachyon::on_unsnoop_command);
        w.slot(&Tachyon::on_unsubscribe_command);
        w.property("name", &Tachyon::name).tag(kTag_Save);
        
        auto wt = writer<TachyonID>();
        wt.description("Unique Tachyon Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Tachyon>);
    }

}


YQ_TACHYON_IMPLEMENT(yq::tachyon::Tachyon)
YQ_TYPE_IMPLEMENT(yq::tachyon::TachyonID)
