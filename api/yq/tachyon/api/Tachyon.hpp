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
    
    protected:
    
        //! Destructor that should never fire
        virtual ~TachyonInfo();
        
        virtual void    sweep_impl() override;
    
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
        
        void    add_interface(const InterfaceInfo*);
        void    add_dispatch(const PBXDispatch*);
    };
    
    //  Call these *BEFORE* the declare
    #define YQ_TACHYON_DATA(...)        using MyData = __VA_ARGS__;
    #define YQ_TACHYON_INFO(...)    YQ_OBJECT_INFO(__VA_ARGS__)
    #define YQ_TACHYON_FIXER(...)   YQ_OBJECT_FIXER(__VA_ARGS__)
    #define YQ_TACHYON_SNAP(...)        using MySnap = __VA_ARGS__;

    #define YQ_TACHYON_DECLARE(...)                             \
        YQ_OBJECT_DECLARE(__VA_ARGS__)


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
        
        using parent_spec_t = std::variant<std::monostate, TachyonID, Tachyon*>;
        
        
        /*! \brief Initialization 
        */
        struct Param {  
            parent_spec_t   parent;
        };
        
        bool                in_thread() const;
        static void         init_info();

        // Inbound mail
        void                mail(rx_t, const PostCPtr&);
        void                mail(rx_t, std::span<PostCPtr const>);
        
        TachyonID           id() const { return { UniqueID::id() }; }
        //ThreadID        id(thread_t) const;
        
        //ThreadID            owning_thread() const { return m_thread; }
        
        virtual TachyonID                       parent() const { return m_parent; }
        virtual std::span<const TachyonID>      children() const;
        
        enum class PostAdvice : uint8_t {
            Reject,     //!< Reject dispatch/handling of the post
            Forward,
            Children,
            Parent
        };
        
        using PostAdviceFlags = Flags<PostAdvice>;

    protected:

        using mutex_t           = tbb::spin_rw_mutex;
        using lock_t            = mutex_t::scoped_lock;
        using control_hash_t    = std::multimap<uint32_t, TachyonID>;

        mutable mutex_t         m_mutex;          // used for guards

    
        #define TXLOCK  \
            lock_t  _lock(m_mutex, true);

        #define TRLOCK                          \
            lock_t  _lock;                      \
            if(!in_thread())                    \
                _lock.acquire(m_mutex, false);

        #define TWLOCK                          \
            lock_t  _lock;                      \
            if(!in_thread())                    \
                _lock.acquire(m_mutex, true);


        friend TachyonPtr;
        friend TachyonCPtr;

        Tachyon(const Param& p={});
        virtual ~Tachyon();
        
        

        /*! \brief Your update routine
        
            Drawing, modeling, etc... goes here
        */
        //disabled_t      update(...);
        
        /*! \brief YOUR update
            \note Do NOT call ticks on other objects!
            
            This is your update, at frame rate.
        */
        virtual void        tick(Context&){}
        
        //! First tick w/o context/frame (basically, bootstrap out messages)
        virtual void        tick(zero_t) {}
        
        
        /*! Advise to the disposition of the post
        
            \note This may be called multithreaded, and shouldn't 
            be exhaustive.  For example, checking that if it's a 
            command with an object binding, it's bound to your type
            of thing.
            
            \return Advise... 
        */
        virtual PostAdviceFlags  advise(const Post&) const;

        
        //virtual void  pre_tick();     // maybe
        //virtual void  post_tick();    // maybe

        
        void        mail(tx_t, const PostCPtr&);
        void        mail(forward_t, const PostCPtr&);
        
        // mail to children
        void        mail(children_t, const PostCPtr&);
        
        // mail to parent
        void        mail(parent_t, const PostCPtr&);

        /*! \brief HANDLES the specified post
        
            \note Override to forward, call base to do normal processing 
            (ie, the dispatch...eventually)
        */
        virtual void    dispatch(const PostCPtr&);
        
        void            snap(TachyonSnap&) const;


        //! Marks us as dirty
        void            mark();

        //TachyonDataPtr      _tick_start();
        
        //void                _tick_done();

        //! When no handler found in dispatch, this gets called
        virtual void    unhandled(const PostCPtr&);

    private:
        friend class Proxy;
        friend class Frame;

        static constexpr const unsigned int     kInvalidThread  = (unsigned int) ~0;
        
        std::vector<PostCPtr>       m_inbox;      //< Inbox (under mutex guard)
        control_hash_t              m_control;    //< Who controls us
        std::vector<TachyonID>      m_children;   //< Children
        std::vector<TachyonID>      m_forward;    //< Those we forward to
        std::vector<TachyonID>      m_snoop;      //< Those eavesdropping on our inbox
        std::vector<TachyonID>      m_subscriber; //< Those we're sending too.
        TachyonID                   m_parent;     //< Parent
        ThreadID                    m_owner;      //< Thread that owns us
        uint64_t                    m_revision      = 0;    //< Revision
        TachyonSnapCPtr             m_snap;                 //< Last snap
        TachyonData*                m_data          = nullptr;
        std::atomic<unsigned int>   m_thread        = kInvalidThread;
        bool                        m_dirty         = false;
        
        
        virtual void                    parent(set_t, TachyonID);
        
        void    tx(const Frame&, TachyonID, std::span<const PostCPtr>);
        
//        std::unique_ptr<Impl>       m;

        //void    _inbound(Frame&);
        //void    _outbound(Frame&);
        
        //void    proxy(ProxyFN&&);
        

        void                                            reset(thread_t);
        std::pair<TachyonDataPtr, TachyonSnapPtr>       tick(thread_t, Context&);
        std::pair<TachyonDataPtr, TachyonSnapPtr>       tick(thread_t, zero_t);
        

        //virtual TachyonDataPtr          tick(Context&);

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;
        
        //void    _inbox(const Frame&, TachyonData&);
        
        //virtual void    _tick

    };
}
