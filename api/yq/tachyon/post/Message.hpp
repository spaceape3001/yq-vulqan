////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Post.hpp>
#include <yq/tachyon/typedef/message.hpp>

namespace yq::tachyon {
    class MessageInfo : public PostInfo {
    public:
        template <typename C> class Writer;

        MessageInfo(std::string_view zName, PostInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    /*! \brief Light weight message
    
        More informational, message to another?  Right now, 
        the Message class is "generic", though it may morph.
    */
    class Message : public Post {
        YQ_OBJECT_INFO(MessageInfo)
        YQ_OBJECT_DECLARE(Message, Post)
    public:
    
        static void init_info();
    
    protected:

        Message(const Param& p);
        virtual ~Message();
    };
}
