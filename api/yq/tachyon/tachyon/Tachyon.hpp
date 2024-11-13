////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>
#include <yq/tachyon/tachyon/TachyonID.hpp>



#include <tbb/spin_rw_mutex.h>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <concepts>

namespace yq::tachyon {
    class Thread;
    class Tachyon;
    
    template <typename T>
    concept SomeTachyon = std::derived_from<T,Tachyon>;
    
    class TachyonInfo : public PBXInfo {
    public:
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, PBXInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Tachyon is thread-aware base post-passing heavy object
    
        The tachyon is the bit that makes the world go around
    */
    class Tachyon : public Object, public RefCount {
        YQ_OBJECT_INFO(TachyonInfo)
        YQ_OBJECT_DECLARE(Tachyon, PBX)
    public:
        
        //! How we deal with posts
        enum class PostMode {
        
            //! Everything direct (no buffering)
            Direct,
            
            //! Other thread into queue, this thread direct
            ThreadSafe,
            
            //! Everything into queues
            Queued,
            
            //! Everything into the one queue (can preserve order, but at a performance cost)
            OneQueue
        };
    
    
        struct Param : public PBX::Param {
        };
    
        Tachyon(const Param&p={});
        ~Tachyon();
        
        unsigned int                    thread_id() const { return m_threadId; }
        
        bool        in_thread() const;
        PostMode    post_mode() const { return m_postMode; }
        
        static void init_info();

        virtual void receive(const PostCPtr&) override;

        //! Checks for attachment
        bool        attached(forward_t, Dispatcher*) const;

        //! TRUE if we're in event replay mode (only one replay at a time)
        bool        in_replay() const;

    protected:
        mutable tbb::spin_rw_mutex      m_mutex;
        
        //! Read-only lock, conditional to object's thread
        #define LOCK                                        \
            tbb::spin_rw_mutex::scoped_lock    _lock;       \
            if(!in_thread())                                \
                _lock.acquire(m_mutex, false);

        //! Write lock, conditional to object's thread
        #define WLOCK                                       \
            tbb::spin_rw_mutex::scoped_lock    _lock;       \
            if(!in_thread())                                \
                _lock.acquire(m_mutex, true);
        
        //! Write lock, unconditional
        #define XLOCK tbb::spin_rw_mutex::scoped_lock  _lock(m_mutex, true);

        // The constructor meant for Thread's use (because... C++ won't let the friend declaration get to it in private)
        Tachyon(const Param&p, thread_t);
        
        //! Thread safe member-assignment
        template <SomeTachyon T, typename V>
        V    assign(V (T::*member), const V& newValue)
        {
            V   temp = newValue;
            {
                XLOCK
                std::swap( static_cast<T*>(this)->*member, temp );
            }
            return temp;
        }
        
        
        //! Replay queued posts (from our thread)
        void    replay(direct_t);

        //! Replay queued posts (from other threads)
        void    replay(thread_t);
        
        //! Replay queued posts (depends on post mode)
        void    replay(all_t);
        
        //! Sets the post mode
        void    set_post_mode(PostMode);
        
        //! Forward said message to the forwarding vector
        void    forward(const PostCPtr&);
        
        //! Attaches to the given dispatcher
        void    attach(forward_t, Dispatcher*);
        
        //! Detaches from the given dispatcher
        void    detach(forward_t, Dispatcher*);
        
    private:
        const uint64_t              m_id;
    
        uint64_t                        m_padding0[7];  // to avoid false sharing
        std::atomic<unsigned int>       m_threadId;
        std::vector<PostCPtr>     m_direct, m_threaded; 
        std::vector<Dispatcher*>  m_forward;       //!< Things that we can forward messages too
        std::atomic<PostMode>           m_postMode  = PostMode::Queued;
        bool                            m_replay    = false;
        
        void    _replay(direct_t);
        void    _replay(thread_t);

        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
}
