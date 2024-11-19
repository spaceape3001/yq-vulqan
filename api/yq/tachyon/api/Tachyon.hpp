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
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/types.hpp>

#include <tbb/spin_rw_mutex.h>
//#include <yq/tachyon/typedef/controller.hpp>
#include <concepts>

namespace yq::tachyon {
    class Thread;
    class InterfaceInfo;
    class Proxy;
    class PBXDispatch;
    class Frame;
    struct TachyonData;
    struct Context;
    
    
    /// TACHYON INFO

    struct TachyonContext;
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

        using dispatch_vec_t     = std::vector<const PBXDispatch*>;
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
            dispatch_vec_t  all, local;
        }                       m_dispatches;
        dispatch_map_t          m_dispatch;
        Types                   m_types;
        
        void    add_interface(const InterfaceInfo*);
        void    add_dispatch(const PBXDispatch*);
    };
    
    //  Call these *BEFORE* the declare
    #define YQ_TACHYON_CONTEXT(...)     using MyContext = __VA_ARGS__;
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
        YQ_TACHYON_CONTEXT(TachyonContext)
        YQ_TACHYON_DATA(TachyonData)
        YQ_TACHYON_FIXER(Fixer)
        YQ_TACHYON_INFO(TachyonInfo)
        YQ_TACHYON_SNAP(TachyonSnap)
        
        YQ_TACHYON_DECLARE(Tachyon, Object)
    public:
        
        enum class PostAdvice {
            None    = 0,    //! No advice (ie, it's not an advisable type)
            Reject,
            Accept
        };
        
        
        /*! \brief Initialization 
        */
        struct Param {  
            /* Reserved for future use */
        };

    
        Tachyon(const Param&p = {});
        ~Tachyon();
        
        bool                in_thread() const;
        static void         init_info();

        //  Inbound mail
        void                mail(rx_t, const PostCPtr&);
        
        TachyonID           id() const { return { UniqueID::id() }; }
        //ThreadID        id(thread_t) const;
        
        //ThreadID            owning_thread() const { return m_thread; }
        
        #if 0
        struct Context {
            double              Δt          = 0.;   //!< Our time step (zero for paused, or first tick)
            double              overclock   = 1.;   //!< Current ratio sim:wall time (1.0 for normal speed, -1.0 for reverse)
            time_point_t        wall;               //!< Wall clock time (start of tick-cycle)
            // current events....?
        };
        #endif
        
        virtual Execution   update(const Frame&, const MyContext&);
        

    protected:
        
        // The constructor meant for Thread's use (because... C++ won't let the friend declaration get to it in private)
        Tachyon(const Param&, thread_t);
        

        /*! \brief Your update routine
        
            Drawing, modeling, etc... goes here
        */
        disabled_t      update(...);
        
        /*! \brief Advise routine for posts
        
        */
        disabled_t      advise(...) const;



        void    proxy_me(std::function<void(Proxy*)>&&);
        
        
        //virtual void  pre_tick();     // maybe
        //virtual void  post_tick();    // maybe

        /*! Advise to the disposition of the post
        
            \note This may be called multithreaded, and shouldn't 
            be exhaustive.  For example, checking that if it's a 
            command with an object binding, it's bound to you type
            of thing.
            
            \note CALL base objects first, if it's none, advise.
            
            \return Advise... 
        */
        virtual PostAdvice  advise(const PostCPtr&) const;
        
        void    mail(tx_t, const PostCPtr&);
        void    mail(forward_t, const PostCPtr&);
        
        //! Override to forward (call base to do normal processing)
        virtual void    handle(const PostCPtr&);
        
        void            snap(TachyonSnap&) const;


        void                mark_dirty();

        TachyonDataPtr      _tick_start();
        
        
        void                _tick_done();

    private:
        friend class Proxy;
        friend class Thread;
        
        static constexpr const unsigned int     kInvalidThread  = (unsigned int) ~0;
        
        struct Impl;
        std::unique_ptr<Impl>       m;

        //void    _inbound(Frame&);
        //void    _outbound(Frame&);
        
        void    proxy(ProxyFN&&);

        virtual TachyonDataPtr          tick(Context&);

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;
        
        //virtual void    _tick

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
    
    
}
