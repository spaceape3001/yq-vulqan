////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/container/RingArray.hpp>
#include <yq/core/LogPriority.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/meta/MetaLookup.hpp>
#include <yt/keywords.hpp>
#include <yt/api/Execution.hpp>
#include <yt/api/ID.hpp>
#include <yt/api/Type.hpp>
#include <yt/msg/MG.hpp>
#include <yt/api/TypedID.hpp>
#include <yt/typedef/frame.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/proxy.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/typedef/thread.hpp>

#include <tbb/spin_rw_mutex.h>
//#include <yt/typedef/controller.hpp>
#include <concepts>
#include <iosfwd>
#include <utility>


namespace yq {
    class Stream;
}

namespace yq::tachyon {
    class InterfaceInfo;
    class Proxy;
    class PBXDispatch;
    struct StartupContext;
    struct Context;
    class TachyonProxyCommand;
    class DestroyCommand;
    class DestroyEvent;
    class TachyonDeleteCommand;
    class RethreadCommand;
    class SnoopCommand;
    class SubscribeCommand;
    class UnsnoopCommand;
    class UnsubscribeCommand;
    class PauseCommand;
    class ResumeCommand;
    
    /// TACHYON INFO

    struct TachyonData;
    struct TachyonSnap;
    
    class TachyonInfo : public ObjectInfo {
    public:
    
        using InterfaceLUC  = MetaLookup<InterfaceInfo>;
        using DispatchMM    = std::unordered_multimap<const PostInfo*, const PBXDispatch*>;
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
        Types       types() const { return m_types; }
    
        const InterfaceLUC& interfaces() const { return m_interfaces.all; }

        using dispatch_vec_t    = std::vector<const PBXDispatch*>;
        using dispatch_span_t   = std::span<const PBXDispatch*>;
        using dispatch_map_t    = std::unordered_map<const PostInfo*, dispatch_span_t>;

        dispatch_span_t     dispatches(const PostInfo*) const;
        
        void                report(Stream&) const;
        void                report(const char* cat="viz", LogPriority pri=LogPriority::Info) const;

    protected:
    
        //! Destructor that should never fire
        virtual ~TachyonInfo();
        
        virtual void    sweep_impl() override;
        using ObjectInfo::set;
        void    set(Type);
        
    private:
        friend class Tachyon;
        friend class Thread;
        
        virtual TachyonSnapPtr   create_snap(const Tachyon&) const = 0;
        virtual TachyonDataPtr   create_data() const = 0;
        virtual void             finalize_data(const Tachyon&, TachyonData&) const = 0;
        
        struct {
            InterfaceLUC    all, local;
        }                       m_interfaces;
        struct {
            dispatch_vec_t  defined, ranked;
        }                       m_dispatches;
        dispatch_map_t          m_dispatch;
        Types                   m_types;
        Execution               m_execution;
        
        void    add_interface(const InterfaceInfo*);
        void    add_dispatch(const PBXDispatch*);
    };
    
    //  Call these *BEFORE* the declare
    #define YQ_TACHYON_DATA(...)        using MyData = __VA_ARGS__;
    #define YQ_TACHYON_INFO(...)    YQ_OBJECT_INFO(__VA_ARGS__)
    #define YQ_TACHYON_FIXER(...)   YQ_OBJECT_FIXER(__VA_ARGS__)
    #define YQ_TACHYON_SNAP(...)        using MySnap = __VA_ARGS__;

    #define YQ_TACHYON_DECLARE(...)                             \
        YQ_OBJECT_DECLARE(__VA_ARGS__)                          \
        template <typename T> friend class Fixer;
        
    #define YQ_TACHYON_IMPLEMENT(...)                           \
        YQ_OBJECT_IMPLEMENT(__VA_ARGS__)

    class Frame;
    struct OutPost;

    /*! \brief Advice for post
    
        
    */
    using PostAdvice    = std::variant<
        std::monostate,     //< Default/unspecified, processing will commence
        accept_k,           //< Unconditionally accept this post
        reject_k,           //< Unconditionally reject this post
        MG,                 //< Accept & forward this post to the given groups
        MGF                 //< Accept & forward this post to the specified group
    >;

    bool unspecified(const PostAdvice& pa);

    /*! \brief Base (heavy) object in the tachyon library
    
        Unfortunately, this class has picked up a bit of heft and isn't light-weight. 
        
        **TASKING** Implement update(const Context&) to get this feature.
    
    
        \note The tachyon is the bit that makes the world go around!
        
        
    */
    class Tachyon : public Object, public UniqueID, public RefCount {
    public:
        template <typename> class Fixer;

        /*
            Stages... this is how the tachyon progresses through life
            
            1.  Preinit (no ticks yet received)
            2.  Setup (setup stage)
            
                Each cycle, the setup() is called (subject to the task-spec).  
                If it succeeds *AND* children are all started, then this tachyon
                will be allowed to run.
                
            3.  Running (general spot it'll loiter)
            
                Each cycle, the tick() is called (subject to the task-spec).
                The tachyon may be paused, at which point, tick isn't called.
                
            4.  Paused (ie, no ticks)
            
                Each cycle, the paused() routine is called (subject to the task-spec).
                Tachyon can alternate between pause & run as often as it'd like.
            
            5.  Teardown is the destruction period before the actual delete.
            
                Each cycle, the teardown() routine is called (subject to the task-spec).
                Once teardown passes, the tachyon is considered "kaput"
                
            6.  Kaput, broken, awaiting destruction

                Once all children have been deleted, this tachyon will proceed
                with delete.
        */

    private:
        YQ_TACHYON_DATA(TachyonData)
        YQ_TACHYON_FIXER(Fixer)
        YQ_TACHYON_INFO(TachyonInfo)
        YQ_TACHYON_SNAP(TachyonSnap)
        
        YQ_TACHYON_DECLARE(Tachyon, Object)
    public:

        class Helper;
        
        /*! \brief Quick identity
        
            Used for logging to the logger (class/id)
        */
        struct Ident {
            std::string_view    metaName;
            std::string_view    tacName;
            uint64_t            id  = 0;
        };
        
        static void         init_info();
        
        const std::vector<TypedID>& children() const { return m_children; }
        
        bool                dying() const;
        
        // Mail this post to the given tachyon...
        //static void         mail(TachyonID, const PostCPtr&);
        
        TachyonID           id() const { return { UniqueID::id() }; }
        
        TypedID             id(typed_k) const;
        
        /*! Short ident meant for logging (meta/ID)
        
            This is used for debug logging... yes, having loads of issues, and
            it's good to have meta/ID/name tuple there.
        */
        Ident               ident() const;
        
        //! Inbound mail to this tachyon
        //! \note Can be used to self-mail commands
        void                mail(const PostCPtr&);
        
        //! Inbound mail to this tachyon
        void                mail(std::span<PostCPtr const>);
        
        //! Our name
        const std::string&  name() const { return m_name; }
        
        //! Thread that owns us
        ThreadID            owner() const;
        
        //! Virtual so derived classes can push children as well
        virtual void        owner(push_k, ThreadID);
        
        //! Our parent
        TypedID             parent() const { return m_parent; }
        
        //! Parent pointer (from a frame)
        //Tachyon*            parent(ptr_k, const Frame&) const;
        
        //TypedID             root(const Frame&) const;

        //Tachyon*            root(ptr_k, const Frame&) const;
        
        bool                running() const;
        
        //! \note NOT thread-safe (yet)
        //! Subscribes the given listener to OUR posts
        void                subscribe(TachyonID listener, MGF grp=MG::General);
        //! \note NOT thread-safe (yet)
        //! Unsubscribes the given listener from OUR posts
        void                unsubscribe(TachyonID listener, MGF grp=ALL);

        struct Param { /* reserved for future use */ 
            name_spec       name;
        };
        
        //! Creates a tachyon (no parent)
        template <SomeTachyon T, typename ... Args>
        static T*   create(Args&&...);
    
        //! Creates a "child" tachyon to the given tachyon
        template <SomeTachyon T, typename ... Args>
        T*          create(child_k, Args&&...);

        //! Creates a "child" tachyon to the given tachyon
        template <SomeTachyon T, typename ... Args>
        T*          create_child(Args&&...);

        /*! \brief Creates a tachyon using its meta information
            
            \note THIS CAN RETURN NULL!  (So chack)
        */
        template <SomeTachyon T>
        static T*   create(const typename T::MyInfo&);

        //template <SomeTachyon T>
        //static T*   create(const typename T::MyInfo&, std::span<const Any> args);

        //! Creates a tachyon (no parent) using the given meta information
        template <SomeTachyon T>
        T*          create(child_k, const typename T::MyInfo&);

        //! Creates a "child" tachyon using the given meta information
        template <SomeTachyon T>
        T*          create_child(const typename T::MyInfo&);

        //template <SomeTachyon T>
        //T*          create(child_t, const typename T::MyInfo&, std::span<const Any> args);

        //! Checks the dirty flag
        //! \note Not 100% thread safe, meant for helpers within the same tick/thread
        bool            dirty() const { return m_dirty; }
        
        bool            starting() const;
        
        bool            paused() const;

    protected:


        enum class Stage {
            
            //! Ctor called, that's it
            Preinit,
            
            //! Setup phase
            Setup,
            
            //! Running
            Running,
            
            //! Paused (can get pushed back to run)
            Paused,
            
            //! Going down!
            Teardown,
            
            //! Done/Busted (ie, ready for delete)
            Kaput
        };
        
                //! Marks us as dirty
        void            mark();

        static bool accepting(const PostAdvice&);
        static bool rejecting(const PostAdvice&);
        static bool unspecified(const PostAdvice&pa);
        static MGF  groups(const PostAdvice&pa);

        using mutex_t           = tbb::spin_rw_mutex;
        using lock_t            = mutex_t::scoped_lock;
        using control_hash_t    = std::multimap<uint32_t, TachyonID>;

        mutable mutex_t         m_mutex;          // used for guards


    
        #define TXLOCK  \
            lock_t  _lock(m_mutex, true);

        #define TRLOCK                          \
            lock_t  _lock;                      \
            if(!in_tick())                      \
                _lock.acquire(m_mutex, false);

        #define TWLOCK                          \
            lock_t  _lock;                      \
            if(!in_tick())                      \
                _lock.acquire(m_mutex, true);


        template <typename T>
        bool    set(T& member, T&& value)
        {
            if(member == value)
                return false;
            member  = std::move(value);
            mark();
            return true;
        }
        
        //  Swaps in a thread-safe manner
        template <typename T>
        T       swap(T& member, T value)
        {
            T   old = std::move(value);
            {
                TXLOCK
                std::swap(member, old);
            }
            return old;
        }

        friend TachyonPtr;
        friend TachyonCPtr;

        Tachyon(const Param& p={});
        virtual ~Tachyon();
        
        
        /*! \brief YOUR update
            \note Do NOT call ticks on other objects!
            
            This is your update, at frame rate.
        */
        virtual Execution  tick(const Context&);
        
        /*! \brief YOUR "paused" update
            \note Do NOT call paused() on other objects!
            
            When paused, this is called in lieu of tick()
        */
        virtual Execution   paused(const Context&);

        /*! \brief Your setup routine
        
            \note Do NOT call setups on other objects!
            
            This is your setup routine, called each frame until accepted.
            
            The unspecified return is considered acceptance.
        */
        virtual Execution   setup(const Context&);
        
        /*! \brief Your teardown (within the tick framework)

            The unspecified return is considered acceptance, and
            will proceed to delete.  
        */
        virtual Execution   teardown(const Context&);
        
        
        /*! Advise to the disposition of the post
        
            SIMPLE tests preferred, for instance, that it's a command
            bound to this tachyon.  Check the base object too,
            and augment as necesary 
        
            \return Advise... 
        */
        virtual PostAdvice  advise(const Post&) const;

        /*! \brief SENDS a post
        
            \note Preferred method to send post
        */
        void            send(const PostCPtr&, PostTarget dst=MG::General);

        /*! \brief DIRECTLY HANDLES the specified post
        
            \note Override to forward, call base to do normal processing 
            (ie, the dispatch...eventually)
            
            \note Inadvisable to routinely call this (aside from the tachyon class itself)
        */
        virtual void    dispatch(const PostCPtr&);
        
        /*! \brief Record snapshot
        
            Assume this is blank-initialized, call base classes
        */
        void            snap(TachyonSnap&) const;
        
        //! Finalize the data
        void            finalize(TachyonData&) const;

        /*! \brief TRUE if we're in tick
        */
        bool            in_tick() const;

        /*! \brief Context
        
            When we're in the tick cycle, the current context.  
            
            \note Using this OUT of tick cycle will lead to 
                segmentation faults!
        */
        const Context&  context() const;

        /*! \brief Our outgoing data
            
            When we're in the tick cycle, the data being generated
            
            \note Using this OUT of tick cycle will lead to 
                segmentation faults!
        */
        TachyonData&    data();


        //! When no handler found in dispatch, this gets called
        virtual void    unhandled(const PostCPtr&);
        
        Stage stage() const { return m_stage; }
        
        uint64_t    cycle() const { return m_cycle; }
        

        void teardown();

    private:
        friend class Proxy;
        friend class Frame;
        friend class Thread;

        
        enum class F : uint8_t {
            //  Set if this object's thread is *MEANT* to be different from parent
            DifferentThread
        };

        Tachyon(init_k, const Param& p={});
        Tachyon(thread_k, const Param& p={});
        
        static void retain(TachyonPtr);
        static void retain(TachyonPtr, ThreadID);

        static constexpr const unsigned int     kInvalidThread  = (unsigned int) ~0;
        
        RingArray<uint64_t,64>      m_last;       //< Filter out the last N messages
        std::vector<PostCPtr>       m_inbox;      //< Inbox (under mutex guard)
        std::vector<OutPost>        m_outbox;     //< Outbox (under mutex guard)
        control_hash_t              m_control;    //< Who controls us
        std::map<TachyonID,MGF>     m_listeners;  //< Who we send to
        std::vector<TachyonID>      m_snoop;      //< Those eavesdropping on our inbox
        ThreadID                    m_owner;      //< Thread that owns us
        uint64_t                    m_revision      = 0;    //< Revision
        TachyonSnapCPtr             m_snap;                 //< Last snap
        TachyonData*                m_data          = nullptr;
        const Context*              m_context       = nullptr;
        std::atomic<unsigned int>   m_thread        = kInvalidThread;
        TypedID                     m_parent;
        std::vector<TypedID>        m_children;
        std::string                 m_name;
        uint64_t                    m_cycle         = 0;
        Stage                       m_stage         = Stage::Preinit;
        bool                        m_dirty         = false;

        Flags<F>                    m_flags = {};
        
        //virtual void                    parent(set_k, TachyonID);
        
        bool    tick_cycle(const Context&);
        
        void    tx(TachyonID, std::span<const PostCPtr>);
        void    tx(TachyonID, PostCPtr);
        
        struct Result {
            TachyonDataCPtr     data;
            TachyonSnapCPtr     snap;
            Execution          execute;
        };

        Result  cycle(const Context&);
        
        //! Sets the parent (thread-safety assumed)
        void    _set_parent(TypedID);
        
        //! Adds the child (thread-safety assumed)
        void    _add_child(TypedID);
        
        void    _add_snoop(TachyonID);
        void    _del_snoop(TachyonID);
        
        //! Deletes the child (thread-safety assumed)
        void    _del_child(TachyonID);
        
        //! Queries for the existence of the child
        bool    _has_child(TachyonID) const;
        
        void    _unsubscribe(TachyonID, MGF);

        void    _subscribe(TachyonID, MGF);
        
        using OldNameFN = std::function<void(std::string&&)>;
        
        bool    _name(name_spec, OldNameFN cap={});
        
//        void    on_proxy_command(const TachyonProxyCommand&);
        
        void    on_destroy_command(const DestroyCommand&);
        void    on_destroy_event(const DestroyEvent&);
        void    on_pause_command(const PauseCommand&);
        void    on_resume_command(const ResumeCommand&);
        void    on_rethread_command(const RethreadCommand&);
        void    on_snoop_command(const SnoopCommand&);
        void    on_subscribe_command(const SubscribeCommand&);
        void    on_unsnoop_command(const UnsnoopCommand&);
        void    on_unsubscribe_command(const UnsubscribeCommand&);

        Execution   tiktok(const Context&);

        void    stage_teardown();
        void    stage_paused();
        void    stage_resume();
        void    stage_running();
        void    stage_kaput();
        bool    check_parent_thread();
        bool    children_started();
    };
    
    ////////////////////////////////////////////
    //  Top-tachyon creates

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create(Args&&... args)
    {
        Ref<T>  tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp);
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create(const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp);
        }
        return tp.ptr();
    }

    ////////////////////////////////////////////
    //  Child-tachyon creates


    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child(Args&&... args)
    {
        Ref<T>   tp  = new T(std::forward<decltype(args)>(args)...);
        retain(tp);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }
    
    template <SomeTachyon T>
    T*   Tachyon::create_child(const typename T::MyInfo& info)
    {
        Ref<T> tp = static_cast<T*>(info.create());
        if(tp){
            retain(tp);
            tp->_set_parent(*this);
            _add_child(*tp);
        }
        return tp.ptr();
    }

    template <SomeTachyon T>
    T*   Tachyon::create(child_k, const typename T::MyInfo& info)
    {
        return create_child<T>(info);
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create(child_k, Args&&... args)
    {
        return create_child<T>(std::forward<decltype(args)>(args)...);
    }

    Stream& operator<<(Stream&, const Tachyon::Ident&);
    
    class Tachyon::Helper {
    protected:
        Helper();
        virtual ~Helper();

        void            mark();
        TypedID         typed() const;
        void            send(PostCPtr, PostTarget tgt=MG::General);
        void            mail(PostCPtr);
    };
    
}

std::ostringstream& operator<<(std::ostringstream&, const yq::tachyon::Tachyon::Ident&);
