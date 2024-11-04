////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>
#include <tbb/spin_rw_mutex.h>

namespace yq::tachyon {
    class Thread;
    
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

        // The constructor meant for Thread's use (because... C++ won't let the friend declaration get to it in private)
        Tachyon(const Param&p, thread_t);

    private:
        std::atomic<unsigned int>       m_threadId;
        //std::vector<Tachyon*>           m_children;
        //Tachyon*                        m_parent = nullptr;

        // The common constructor used between the two
        Tachyon(const Param&p, init_t);
    };
}
