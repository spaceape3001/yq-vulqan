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
#include <tachyon/keywords.hpp>
#include <tachyon/api/Execution.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/api/Type.hpp>
#include <tachyon/api/MG.hpp>
#include <tachyon/api/TypedID.hpp>
#include <tachyon/typedef/frame.hpp>
#include <tachyon/typedef/post.hpp>
#include <tachyon/typedef/proxy.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <tachyon/typedef/thread.hpp>

#include <tbb/spin_rw_mutex.h>
//#include <tachyon/typedef/controller.hpp>
#include <concepts>
#include <iosfwd>
#include <utility>


namespace yq {
    class Stream;
}

namespace yq::tachyon {
    class InterfaceMeta;
    class Proxy;
    class PBXDispatch;
    struct StartupContext;
    struct Context;
    class AddChildCommand;
    class DestroyCommand;
    class DestroyEvent;
    class RethreadCommand;
    class UnsnoopCommand;
    class UnsubscribeCommand;
    class PauseCommand;
    class RemoveChildCommand;
    class ResumeCommand;
    class SetAttributeCommand;
    class SetNameCommand;
    class SetParentCommand;
    class SnoopCommand;
    class SubscribeCommand;
    //class TachyonDeleteCommand;
    //class TachyonProxyCommand;
    
    /// TACHYON INFO

    class AssetProperty;
    struct TachyonData;
    struct TachyonSnap;
    class DelegateProperty;
    
    class TachyonMeta : public ObjectInfo {
    public:
    
        using InterfaceLUC  = MetaLookup<InterfaceMeta>;
        using DispatchMM    = std::unordered_multimap<const PostMeta*, const PBXDispatch*>;
        using DelegateLUC   = MetaLookup<DelegateProperty>;
        using AssetLUC      = MetaLookup<AssetProperty>;
        
        template <typename C> class Writer;

        TachyonMeta(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
        Types       types() const { return m_types; }
    
        const MetaLookup<InterfaceMeta>&    interfaces(bool all=false) const;

        const MetaLookup<InterfaceMeta>&    interfaces(all_k) const { return m_interfaces.all; }
        
        const MetaLookup<InterfaceMeta>&    interfaces(local_k) const { return m_interfaces.local; }

        const MetaLookup<AssetProperty>&    assets(bool all=false) const;

        const MetaLookup<AssetProperty>&    assets(all_k) const { return m_assets.all; }
        
        const MetaLookup<AssetProperty>&    assets(local_k) const { return m_assets.local; }
        
        //! Finds the asset property (ALL is assumed)
        const AssetProperty*                asset(std::string_view) const;

        const MetaLookup<DelegateProperty>&    delegates(bool all=false) const;

        const MetaLookup<DelegateProperty>&    delegates(all_k) const { return m_delegates.all; }
        
        const MetaLookup<DelegateProperty>&    delegates(local_k) const { return m_delegates.local; }

        //! Finds the delegate property (ALL is assumed)
        const DelegateProperty*             delegate(std::string_view) const;

        using dispatch_vec_t    = std::vector<const PBXDispatch*>;
        using dispatch_span_t   = std::span<const PBXDispatch*>;
        using dispatch_map_t    = std::unordered_map<const PostMeta*, dispatch_span_t>;

        dispatch_span_t     dispatches(const PostMeta*) const;
        
        void                report(Stream&) const;
        void                report(const char* cat="viz", LogPriority pri=LogPriority::Info) const;

        //! Category (might move upward if useful)
        std::string_view category() const { return m_category; }

        static const std::vector<const TachyonMeta*>&    all();

    protected:
    
        //! Destructor that should never fire
        virtual ~TachyonMeta();
        
        virtual void    sweep_impl() override;
        using ObjectInfo::set;
        void    set(Type);
        
    private:
        friend class Tachyon;
        friend class Thread;
        friend class AssetProperty;
        friend class DelegateProperty;
        
        struct Repo;
        static Repo& repo();
        
        virtual TachyonSnapPtr   create_snap(const Tachyon&) const = 0;
        virtual TachyonDataPtr   create_data() const = 0;
        virtual void             finalize_data(const Tachyon&, TachyonData&) const = 0;
        
        struct {
            InterfaceLUC    all, local;
        }                       m_interfaces;
        struct {
            DelegateLUC     all, local;
        }   m_delegates;
        struct {
            AssetLUC        all, local;
        }   m_assets;
        struct {
            dispatch_vec_t  defined, ranked;
        }                       m_dispatches;
        dispatch_map_t          m_dispatch;
        Types                   m_types;
        Execution               m_execution;
        std::string_view        m_category;     // shouldn't have to move this upward, but might.... (later)
        
        //  delegates
        
        void    add_interface(const InterfaceMeta*);
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
        
    #define YQ_TACHYON_BASE(...)    YQ_OBJECT_BASE(__VA_ARGS__)
    #define YQ_TACHYON_DECLARE_BASELESS(...)                    \
        YQ_OBJECT_DECLARE_BASELESS(__VA_ARGS__)                 \
        template <typename T> friend class Fixer;

    #define YQ_TACHYON_IMPLEMENT(...)                           \
        YQ_OBJECT_IMPLEMENT(__VA_ARGS__)

/*! \brief Force a info binding declaration

    This is useful when there's a diamond pattern forming, to resolve that YES, this 
    is a known meta-tachyon
*/
    #define YQ_TACHYON_FORCE(...)                                   \
        namespace yq {                                                      \
            template <>                                                     \
            struct InfoBinder<__VA_ARGS__>  : public std::true_type {       \
                using Info = typename __VA_ARGS__::MyInfo;                  \
                static constexpr const bool Defined         = true;         \
                static constexpr const bool IsObject        = true;         \
                static constexpr const bool IsType          = false;        \
                static constexpr const bool IsCompound      = true;         \
                static constexpr const bool IsInterface     = false;        \
                static constexpr const bool IsProxy         = false;        \
                static constexpr const bool IsTachyon       = true;         \
                static const Info&   bind() { return edit(); }          \
                static Info&         edit()  { return const_cast<Info&>(__VA_ARGS__::staticMetaInfo()); } \
            };                                                              \
        } 

    class Frame;
    struct OutPost;

    /*! \brief Advice for post
    
        
    */
    using PostAdvice    = std::variant<
        std::monostate,     //< Default/unspecified, processing will commence
        accept_k,           //< Unconditionally accept this post
        reject_k,           //< Unconditionally reject this post
        TachyonID,          //< Accept & forward to this tachyon
        StdThread,          //< Accept & forward directly to this thread
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
        YQ_TACHYON_INFO(TachyonMeta)
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
            
            friend std::ostringstream& operator<<(std::ostringstream& out, const Ident& me)
            {
                me.write(out);
                return out;
            }
            
            friend log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream& out, const Ident& me)
            {
                me.write(out);
                return out;
            }

            friend Stream& operator<<(Stream& out, const Ident& me)
            {
                me.write(out);
                return out;
            }

            void write(std::ostringstream&) const;
            void write(log4cpp::CategoryStream&) const;
            void write(Stream&) const;
        };
        
        static void         init_info();
        
        Any                 attribute(int) const;
        Any                 attribute(const std::string&) const;
        
        
        const std::vector<TypedID>& children() const { return m_children; }
        
        bool                dying() const;
        
        bool                has_attribute(int) const;
        bool                has_attribute(const std::string&) const;
        
        // Mail this post to the given tachyon...
        //static void         mail(TachyonID, const PostCPtr&);
        
        TachyonID           id() const { return { UniqueID::id() }; }
        
        TypedID             id(typed_k) const;
        
        /*! Short ident meant for logging (meta/ID)
        
            This is used for debug logging... yes, having loads of issues, and
            it's good to have meta/ID/name tuple there.
        */
        Ident               ident() const;
        
        bool                kaput() const;
        
        //! Inbound mail to this tachyon
        //! \note Can be used to self-mail commands
        void                mail(const PostCPtr&);
        
        //! Inbound mail to this tachyon
        void                mail(std::span<PostCPtr const>);
        
        //! Inbound to a specific tachyon (bypasses send) and requires recipient to be on the current frame
        static void         mail(TachyonID, const PostCPtr&);
        
        //! Inbound to a specific tachyon (bypasses send) and requires recipient to be on the current frame
        static void         mail(StdThread, const PostCPtr&);

        //! Our name
        const std::string&  name() const { return m_name; }
        
        //! Thread that owns us
        ThreadID            owner() const;
        
        //! Virtual so derived classes can push children as well
        virtual void        owner(push_k, ThreadID);
        
        void                owner(push_k, StdThread);

        //! Our parent
        TypedID             parent() const { return m_parent; }
        
        //! Parent pointer (from a frame)
        //Tachyon*            parent(ptr_k, const Frame&) const;
        
        //TypedID             root(const Frame&) const;

        //Tachyon*            root(ptr_k, const Frame&) const;
        
        bool                running() const;

        /*! \brief SENDS a post
        
            \note Preferred method to send post
        */
        void                send(const PostCPtr&, PostTarget dst=MG::General);

        //! Sets name on next tick
        void                set_name(std::string_view);

        //! Sets parent on next tick (with implied add/remove child) 
        void                set_parent(TachyonSpec);
        
        
        //! \note NOT thread-safe (yet)
        //! Subscribes the given listener to OUR posts
        void                subscribe(TachyonID listener, MGF grp=MG::General);

        TypedID             typed_id() const;

        //! \note NOT thread-safe (yet)
        //! Unsubscribes the given listener from OUR posts
        void                unsubscribe(TachyonID listener, MGF grp=ALL);

        struct Param { /* reserved for future use */ 
            name_spec       name;
        };
        
        //! Creates a tachyon (no parent)
        template <SomeTachyon T, typename ... Args>
        static T*   create(Args&&...);
    
        /*! \brief Creates a tachyon using its meta information
            
            \note THIS CAN RETURN NULL!  (So chack)
        */
        template <SomeTachyon T>
        static T*   create(const typename T::MyInfo&);


        //! Creates a tachyon in the sim/game-thread
        template <SomeTachyon T, typename ... Args>
        static T*   create_on(StdThread, Args&&...);

        //! Creates a tachyon in the sim/game-thread
        template <SomeTachyon T, typename ... Args>
        static T*   create_on(ThreadID, Args&&...);
        
        //! Creates a tachyon on the Application thread (caution here)
        template <SomeTachyon T=Tachyon>
        static T*   create_on(StdThread, const typename T::MyInfo&);

        //! Creates a tachyon on the Application thread (caution here)
        template <SomeTachyon T=Tachyon>
        static T*   create_on(ThreadID, const typename T::MyInfo&);

        //! Creates a "child" tachyon to the given tachyon
        template <SomeTachyon T, typename ... Args>
        T*          create_child(Args&&...);

        //! Creates a "child" tachyon using the given meta information
        template <SomeTachyon T=Tachyon>
        T*          create_child(const typename T::MyInfo&);

        //! Creates a "child" tachyon to the given tachyon
        template <SomeTachyon T, typename ... Args>
        T*          create_child_on(ThreadID, Args&&...);

        //! Creates a "child" tachyon to the given tachyon
        template <SomeTachyon T, typename ... Args>
        T*          create_child_on(StdThread, Args&&...);

        //! Creates a "child" tachyon using the given meta information
        template <SomeTachyon T=Tachyon>
        T*          create_child_on(StdThread, const typename T::MyInfo&);

        template <SomeTachyon T=Tachyon>
        T*          create_child_on(ThreadID, const typename T::MyInfo&);


        //template <SomeTachyon T>
        //static T*   create(const typename T::MyInfo&, std::span<const Any> args);


        //template <SomeTachyon T>
        //T*          create(child_t, const typename T::MyInfo&, std::span<const Any> args);

        //! Checks the dirty flag
        //! \note Not 100% thread safe, meant for helpers within the same tick/thread
        bool            dirty() const { return m_dirty; }
        
        bool            starting() const;
        
        bool            paused() const;

        //! Initiates the teardown/destruction process
        void            cmd_destroy() { teardown(); }

        //! Initiates the teardown/destruction process
        void            cmd_teardown() { teardown(); }

        //! called by the save/load API (assumed thread-safe)
        void    load_set_parent(TypedID);

        //! called by the save/load API (assumed thread-safe)
        void    load_add_child(TypedID);
        
        const AttrIDMap&    prog_attributes() const { return m_progAttrs; }
        const AttrKeyMap&   user_attributes() const { return m_userAttrs; }

        //! Replaces/sets all the prog attributes
        //! \note Callers need to assure thread-safety (ie... loading from disk)
        void    load_attributes(const AttrIDMap&);
        
        //! Replaces/sets all the prog attributes
        //! \note Callers need to assure thread-safety (ie... loading from disk)
        void    load_attributes(AttrIDMap&&);

        //! Replaces/sets all the user attributes
        //! \note Callers need to assure thread-safety (ie... loading from disk)
        void    load_attributes(const AttrKeyMap&);

        //! Replaces/sets all the user attributes
        //! \note Callers need to assure thread-safety (ie... loading from disk)
        void    load_attributes(AttrKeyMap&&);
        
        void    set_attribute(int, const Any&);
        void    set_attribute(std::string_view, const Any&);

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

        void    info_log_post(const Post&) const;


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
        
        //! An asynchronous task on the given thread
        //! \return Future of the appropriate type
        template <typename Pred>
        auto    tasker(StdThread, Pred&&);
        
        //! An asynchronous task on the given thread
        //! \return Future of the appropriate type
        template <typename Pred>
        auto    tasker(ThreadID,  Pred&&);

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
        static void retain(TachyonPtr, StdThread);

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
        AttrIDMap                   m_progAttrs;
        AttrKeyMap                  m_userAttrs;
        TypedID                     m_parent;
        std::vector<TypedID>        m_children;
    protected:
        std::string                 m_name;
    private:
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
        
        void    on_add_child_command(const AddChildCommand&);
        void    on_destroy_command(const DestroyCommand&);
        void    on_destroy_event(const DestroyEvent&);
        void    on_pause_command(const PauseCommand&);
        void    on_remove_child_command(const RemoveChildCommand&);
        void    on_resume_command(const ResumeCommand&);
        void    on_rethread_command(const RethreadCommand&);
        void    on_set_attribute_command(const SetAttributeCommand&);
        void    on_set_name_command(const SetNameCommand&);
        void    on_set_parent_command(const SetParentCommand&);
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

YQ_TYPE_DECLARE(yq::tachyon::TachyonID)
