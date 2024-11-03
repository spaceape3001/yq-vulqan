////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>

namespace yq::tachyon {
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
    
        using post::PBX::Param;
    
        Tachyon(const Param&p={});
        ~Tachyon();
        
        unsigned int                    thread_id() const { return m_threadId; }
        
        static void init_info();

    protected:
        Tachyon(const Param&p, thread_t);
        
    private:
        std::atomic<unsigned int>        m_threadId;
    };
}
