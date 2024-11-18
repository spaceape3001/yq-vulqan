////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/MetaObject.hpp>
#include <yq/meta/MetaLookup.hpp>
#include <yq/tachyon/keywords.hpp>
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

    struct TachyonData;
    struct TachyonSnap;
    
    class TachyonInfo : public MetaObjectInfo {
    public:

        using InterfaceLUC  = MetaLookup<InterfaceInfo>;
        using DispatchMM    = std::unordered_multimap<const PostInfo*, const PBXDispatch*>;
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, MetaObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
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
    

    /*! \brief Tachyon is thread-aware base post-passing heavy object
    
        The tachyon is the bit that makes the world go around
    */
    class Tachyon : public MetaObject {
    public:
        template <typename> class Fixer;

    private:
        YQ_OBJECT_INFO(TachyonInfo)
        YQ_OBJECT_FIXER(Fixer)
        YQ_OBJECT_DECLARE(Tachyon, MetaObject)
    public:
        
        using MyData    = TachyonData;
        
        
        /*! \brief Initialization 
        */
        struct Param {  
            /* Reserved for future use */
        };

    
        Tachyon(const Param&p = {});
        ~Tachyon();
        
        bool            in_thread() const;
        static void     init_info();

        //  Inbound mail
        void            mail(rx_t, const PostCPtr&);
        
        TachyonID       id(tachyon_t={}) const { return { UniqueID::id() }; }
        ThreadID        id(thread_t) const;


    protected:
        mutable tbb::spin_rw_mutex      m_mutex;
        
        //! Read-only lock, conditional to object's thread
        #define TRLOCK                                          \
            tbb::spin_rw_mutex::scoped_lock    _lock;           \
            if(!in_thread())                                    \
                _lock.acquire(m_mutex, false);

        //! Write lock, conditional to object's thread
        #define TWLOCK                                          \
            tbb::spin_rw_mutex::scoped_lock    _lock;           \
            if(!in_thread())                                    \
                _lock.acquire(m_mutex, true);
        
        //! Write lock, unconditional
        #define TXLOCK tbb::spin_rw_mutex::scoped_lock  _lock(m_mutex, true);

        // The constructor meant for Thread's use (because... C++ won't let the friend declaration get to it in private)
        Tachyon(const Param&, thread_t);
        
        //! Thread safe member-assignment
        template <SomeTachyon T, typename V>
        V    assign(V (T::*member), const V& newValue)
        {
            V   temp = newValue;
            {
                TXLOCK
                std::swap( static_cast<T*>(this)->*member, temp );
            }
            changed();
            return temp;
        }
        
        
        void    proxy_me(std::function<void(Proxy*)>&&);
        
        // This is where you get your processing should be done
        virtual void    update(Context&){}
        
        //virtual void  pre_tick();     // maybe
        //virtual void  post_tick();    // maybe

        enum class PostAdvice {
            None    = 0,    //! No advice (ie, it's not an advisable type)
            Reject,
            Accept
        };
        
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



    private:
        friend class Proxy;
        
        static constexpr const unsigned int     kInvalidThread  = (unsigned int) ~0;

        // Mail boxes....
        std::vector<PostCPtr>               m_mailbox;      //!< Inbound (under mutex guard)
        std::vector<ProxyFN>                m_proxied;      //!< Inbound proxy changes (under mutex guard)
        std::vector<PostCPtr>               m_outbox;       //!< Outbound
        std::vector<PostCPtr>               m_forward;      //!< Forwarding posts
        std::vector<TachyonID>              m_snoops;       //!< Those eavesdropping on us
        std::vector<TachyonID>              m_forwards;     //!< Those we'll forward (conditionally)
        std::vector<TachyonID>              m_subscribers;  //!< Who we're broadcasting to
        std::multimap<uint32_t, TachyonID>  m_control;      //!< Those controlling us
        ThreadID                            m_thread;
        
        //! Current thread ID if tick-processing (invalid outside of tick)
        std::atomic<unsigned int>           m_threadId  = kInvalidThread;
        bool                                m_dirty     = false;
        
        //void    _inbound(Frame&);
        //void    _outbound(Frame&);
        
        void    proxy(ProxyFN&&);

        virtual TachyonDataPtr              tick(Context&);

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;
        
        //virtual void    _tick

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
    
    #define YQ_TACHYON_DECLARE(...) YQ_OBJECT_DECLARE(__VA_ARGS__)
    
}
