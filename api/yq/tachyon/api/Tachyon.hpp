////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/MetaObject.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/types.hpp>

#include <tbb/spin_rw_mutex.h>
#include <yq/tachyon/typedef/controller.hpp>
#include <concepts>

namespace yq::tachyon {
    class Thread;
    
    class TachyonInfo : public MetaObjectInfo {
    public:
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, MetaObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
        Types       types() const { return m_types; }
        
    private:
        Types       m_types;
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
            std::string_view        name;
        };
    
        Tachyon(const Param&p = {});
        ~Tachyon();
        
        unsigned int    thread_id() const { return m_threadId; }
        bool            in_thread() const;
        static void     init_info();

        //  Inbound mail
        void        mail(const PostCPtr&);
        void        mail(proxy_t, const PostCPtr&);

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
        
        
        
        
        


        //! Forward said message to the forwarding vector
        void    forward(const PostCPtr&);
        
        //! Attaches to the given dispatcher
        void    attach(forward_t, Dispatcher*);
        
        //! Detaches from the given dispatcher
        void    detach(forward_t, Dispatcher*);
        
        enum class PostAdvice {
            Reject,
            Accept
        };
        
        virtual PostAdvice  advise(const PostCPtr&) const;
        
    private:

        std::string                 m_name;
        std::atomic<unsigned int>   m_threadId;


        // Mail boxes....
        std::vector<PostCPtr>               m_direct, m_threaded, m_outbound; 
        std::vector<TachyonID>              m_snoops;       //!< Those eavesdropping on us
        std::vector<TachyonID>              m_eavesdrops;   //!< Who we're eavesdropping on
        std::vector<TachyonID>              m_senders;      //!< Who we're broadcasting from
        std::vector<TachyonID>              m_recievers;    //!< Who we're broadcasting to
        std::multimap<uint32_t, TachyonID>  m_control;      //!< Those controlling us
        
        
        
        void    _replay(direct_t);
        void    _replay(thread_t);

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
}
