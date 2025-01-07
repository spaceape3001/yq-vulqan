////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Post.hpp>
#include <yt/typedef/message.hpp>

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
    
        struct Param {}; //< DEPRECATED
    
    protected:

        Message(const Param& p={}); //< DEPRECATED

        Message(const Header&);
        Message(const Message&,const Header&);
        virtual ~Message();
        
    private:
        Message(const Message&) = delete;
        Message(Message&&) = delete;
        Message& operator=(const Message&) = delete;
        Message& operator=(Message&&) = delete;
    };
}
