////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/meta/MetaLookup.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Execution.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/MG.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/frame.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/types.hpp>

#include <tbb/spin_rw_mutex.h>
//#include <yq/tachyon/typedef/controller.hpp>
#include <concepts>

namespace yq::tachyon {
    class InterfaceInfo;
    class Proxy;
    class PBXDispatch;
    struct Context;
    class TachyonProxyCommand;
    
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
        Execution           execution() const { return m_execution; }
    
    protected:
    
        //! Destructor that should never fire
        virtual ~TachyonInfo();
        
        virtual void    sweep_impl() override;
        using ObjectInfo::set;
        void    set(Type);
        
    private:
        friend class Tachyon;
        
        virtual TachyonSnapPtr   create_snap(Tachyon*) const = 0;
        virtual TachyonDataPtr   create_data() const = 0;
        
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

    using PostAdvice = std::variant<std::monostate, accept_t, reject_t, MG, MGF>;

    /*! \brief Base (heavy) object in the tachyon library
    
        Unfortunately, this class has picked up a bit of heft and isn't light-weight. 
        
        **TASKING** Implement update(Context&) to get this feature.
    
    
        \note The tachyon is the bit that makes the world go around!
        
        
    */
    class Tachyon : public Object, public UniqueID, public RefCount {
    public:
        template <typename> class Fixer;

    private:
        YQ_TACHYON_DATA(TachyonData)
        YQ_TACHYON_FIXER(Fixer)
        YQ_TACHYON_INFO(TachyonInfo)
        YQ_TACHYON_SNAP(TachyonSnap)
        
        YQ_TACHYON_DECLARE(Tachyon, Object)
    public:
        
        static void         init_info();
        
        
        // Inbound mail
        void                mail(const PostCPtr&);
        void                mail(std::span<PostCPtr const>);
        
        static void         mail(TachyonID, const PostCPtr&);
        
        TachyonID           id() const { return { UniqueID::id() }; }
        
        const std::string&  name() const { return m_name; }
        
        ThreadID            owner() const;
        
        bool                owner(push_t, ThreadID);
        
        TypedID             parent() const { return m_parent; }
        
        Tachyon*            parent(const Frame&) const;
        
        
        //! \note NOT thread-safe (yet)
        void                subscribe(TachyonID, MGF grp=MG::General);
        //! \note NOT thread-safe (yet)
        void                unsubscribe(TachyonID, MGF grp=ALL);

        struct Param { /* reserved for future use */ 
            name_spec       name;
        };
        
        template <SomeTachyon T, typename ... Args>
        static T*   create(Args...);
    
        template <SomeTachyon T, typename ... Args>
        T*          create(child_t, Args...);

        template <SomeTachyon T, typename ... Args>
        T*          create_child(Args...);

    protected:


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

        friend TachyonPtr;
        friend TachyonCPtr;

        Tachyon(const Param& p={});
        virtual ~Tachyon();
        
        
        /*! \brief YOUR update
            \note Do NOT call ticks on other objects!
            
            This is your update, at frame rate.
        */
        virtual Execution   tick(Context&);
        
        
        /*! Advise to the disposition of the post
        
            SIMPLE tests preferred, for instance, that it's a command
            bound to this tachyon.  Check the base object too,
            and augment as necesary 
        
            \return Advise... 
        */
        virtual PostAdvice  advise(const Post&) const;

        void            send(const PostCPtr&, MGF dst=MG::General);

        /*! \brief HANDLES the specified post
        
            \note Override to forward, call base to do normal processing 
            (ie, the dispatch...eventually)
        */
        virtual void    dispatch(const PostCPtr&);
        
        /*! \brief Record snapshot
        
            Assume this is blank-initialized, call base classes
        */
        void            snap(TachyonSnap&) const;

        /*! \brief TRUE if we're in tick
        */
        bool            in_tick() const;

        /*! \brief Context
        
            When we're in the tick cycle, the current context.  
            
            \note Using this OUT of tick cycle will lead to 
                segmentation faults!
        */
        Context&        context() const;

        /*! \brief Our outgoing data
            
            When we're in the tick cycle, the data being generated
            
            \note Using this OUT of tick cycle will lead to 
                segmentation faults!
        */
        TachyonData&    data();
        
        bool            dirty() const { return m_dirty; }
        
        /*! \brief Frame
        
            When we're in the tick cycle, the current frame
            
            \note Using this OUT of tick cycle will lead to 
                segmentation faults!
        */
        const Frame&    frame() const;

        //! Marks us as dirty
        void            mark();

        //! When no handler found in dispatch, this gets called
        virtual void    unhandled(const PostCPtr&);

    private:
        friend class Proxy;
        friend class Frame;
        friend class Thread;

        Tachyon(init_t, const Param& p={});
        Tachyon(thread_t, const Param& p={});
        
        static void retain(TachyonPtr);
        static void retain(TachyonPtr, ThreadID);

        static constexpr const unsigned int     kInvalidThread  = (unsigned int) ~0;
        
        std::vector<PostCPtr>       m_inbox;      //< Inbox (under mutex guard)
        std::vector<OutPost>        m_outbox;     //< Outbox (under mutex guard)
        control_hash_t              m_control;    //< Who controls us
        std::map<TachyonID,MGF>     m_listeners;  //< Who we send to
        std::vector<TachyonID>      m_snoop;      //< Those eavesdropping on our inbox
        ThreadID                    m_owner;      //< Thread that owns us
        uint64_t                    m_revision      = 0;    //< Revision
        TachyonSnapCPtr             m_snap;                 //< Last snap
        TachyonData*                m_data          = nullptr;
        Context*                    m_context       = nullptr;
        std::atomic<unsigned int>   m_thread        = kInvalidThread;
        TypedID                     m_parent;
        std::vector<TypedID>        m_children;
        std::string                 m_name;
        bool                        m_dirty         = false;
        
        //virtual void                    parent(set_t, TachyonID);
        
        void    tx(TachyonID, std::span<const PostCPtr>);
        void    tx(TachyonID, PostCPtr);
        
        struct Result {
            TachyonDataCPtr     data;
            TachyonSnapCPtr     snap;
            Execution           execute;
        };

        Result  cycle(Context&);
        
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
        
        void    slot_proxy_command(const TachyonProxyCommand&);
    };

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create(Args... args)
    {
        Ref<T>  tp  = new T(args...);
        retain(tp);
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create_child(Args... args)
    {
        Ref<T>   tp  = new T(args...);
        retain(tp);
        tp->_set_parent(*this);
        _add_child(*tp);
        return tp.ptr();
    }

    template <SomeTachyon T, typename ... Args>
    T*  Tachyon::create(child_t, Args... args)
    {
        return create_child<T>(args...);
    }
}
