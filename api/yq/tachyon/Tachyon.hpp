////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>
#include <tbb/spin_rw_mutex.h>
#include <concepts>

namespace yq::tachyon {
    class Thread;
    class Tachyon;
    
    template <typename T>
    concept SomeTachyon = std::derived_from<T,Tachyon>;
    
    class TachyonInfo : public post::PBXInfo {
    public:
        
        template <typename C> class Writer;

        TachyonInfo(std::string_view zName, post::PBXInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Tachyon is thread-aware base post-passing heavy object
    
        The tachyon is the bit that makes the world go around
    */
    class Tachyon : public post::PBX {
        YQ_OBJECT_INFO(TachyonInfo)
        YQ_OBJECT_DECLARE(Tachyon, post::PBX)
    public:
    
        struct Param : public post::PBX::Param {
        };
    
        Tachyon(const Param&p={});
        ~Tachyon();
        
        unsigned int                    thread_id() const { return m_threadId; }
        
        bool    in_thread() const;
        
        static void init_info();

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

    private:
        std::atomic<unsigned int>       m_threadId;
        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
}
