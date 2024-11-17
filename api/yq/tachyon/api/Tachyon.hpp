////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/MetaObject.hpp>
#include <yq/meta/MetaLookup.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/types.hpp>

#include <tbb/spin_rw_mutex.h>
//#include <yq/tachyon/typedef/controller.hpp>
#include <concepts>

namespace yq::tachyon {
    class Thread;
    class InterfaceInfo;
    class Proxy;
    class Frame;
    
    class PBXDispatch {
    public:
        class Writer;

        const PostInfo*     post() const { return m_post; }
        const TachyonInfo*  tachyon() const { return m_tachyon; }
    
            //! Lets us know the syntax being invoked
        virtual const char* debug_string() const = 0;
        std::string_view    name() const { return m_name; }
        
    protected:
        const PostInfo*     m_post          = nullptr;
        const TachyonInfo*  m_tachyon       = nullptr;
        std::string_view    m_name;
        
        friend class Tachyon;
        PBXDispatch(){}
        virtual ~PBXDispatch(){}
        
        virtual bool        dispatch(PBX&, const PostCPtr&) const = 0;
    };
    
    
    class TachyonInfo : public MetaObjectInfo {
    public:

        using InterfaceLUC  = MetaLookup<InterfaceInfo>;
        using DispatchMM    = std::unordered_multimap<const PostInfo*, const PBXDispatch*>;
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, MetaObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
        Types       types() const { return m_types; }
    
        const InterfaceLUC& interfaces() const { return m_interfaces.all; }
    
    protected:
    
        //! Destructor that should never fire
        virtual ~TachyonInfo();
        
        virtual void    sweep_impl() override;
        
    
    private:
        friend class Proxy;
    
        using dispatch_vec_t     = std::vector<const PBXDispatch*>;
        using dispatch_span_t   = std::span<const PBXDispatch*>;
        using dispatch_map_t    = std::unordered_map<const PostInfo*, dispatch_span_t>;
        
        struct {
            InterfaceLUC    all, local;
        }                       m_interfaces;
        struct {
            dispatch_vec_t  all, local;
        }                       m_dispatches;
        dispatch_map_t          m_dispatch;
        Types                   m_types;
        std::vector<ProxyFN>    m_proxied;
        
        void    add_interface(const InterfaceInfo*);
        void    add_dispatch(const PBXDispatch*);
        
        void    proxy(ProxyFN&&);
    };
    
    
    class Proxy;
    

    /*! \brief Tachyon is thread-aware base post-passing heavy object
    
        The tachyon is the bit that makes the world go around
    */
    class Tachyon : public MetaObject {
        YQ_OBJECT_INFO(TachyonInfo)
        YQ_OBJECT_DECLARE(Tachyon, MetaObject)
    public:
        
        struct Param {
            /* Reserved for future use */
        };
    
        Tachyon(const Param&p = {});
        ~Tachyon();
        
        unsigned int    thread_id() const { return m_threadId; }
        bool            in_thread() const;
        static void     init_info();

        //  Inbound mail
        void        mail(rx_t, const PostCPtr&);
        //void        mail(proxy_t, const PostCPtr&);

        //virtual void receive(const PostCPtr&) override;

        //! Checks for attachment
        //bool        attached(forward_t, Dispatcher*) const;

        //! TRUE if we're in event replay mode (only one replay at a time)
        //bool        in_replay() const;

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
                XLOCK
                std::swap( static_cast<T*>(this)->*member, temp );
            }
            changed();
            return temp;
        }
        
        //! Replay queued posts (from our thread)
        void    replay(direct_t);

        //! Replay queued posts (from other threads)
        void    replay(thread_t);

        //! Replay from proxied posts
        void    replay(proxy_t);
        
        //! Replay queued posts (depends on post mode)
        void    replay(all_t);
        
        
        void    proxy_me(std::function<void(Proxy*)>&&);
        
        void    tick(const AppFrame&);


        //! Forward said message to the forwarding vector
        void    forward(const PostCPtr&);
        
        //! Attaches to the given dispatcher
        void    attach(forward_t, Dispatcher*);
        
        //! Detaches from the given dispatcher
        void    detach(forward_t, Dispatcher*);
        
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
        
        void    mail(TX, const PostCPtr&);
        
    private:

        std::atomic<unsigned int>           m_threadId;

        // Mail boxes....
        std::vector<PostCPtr>               m_mailbox;      //!< Inbound (under mutex guard)
        std::vector<PostCPtr>               m_outbox;       //!< Outbound
        std::vector<TachyonID>              m_snoops;       //!< Those eavesdropping on us
        std::vector<TachyonID>              m_subscribers;  //!< Who we're broadcasting to
        std::multimap<uint32_t, TachyonID>  m_control;      //!< Those controlling us
        
        
        void    _inbound(Frame&);
        void    _outbound(Frame&);
        

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
}
