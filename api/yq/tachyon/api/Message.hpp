////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/typedef/message.hpp>

namespace yq::tachyon {
    class MessageMeta : public PostMeta {
    public:
        template <typename C> class Writer;

        MessageMeta(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };
    
    /*! \brief Light weight message
    
        More informational, message to another?  Right now, 
        the Message class is "generic", though it may morph.
    */
    class Message : public Post {
        YQ_OBJECT_META(MessageMeta)
        YQ_OBJECT_DECLARE(Message, Post)
    public:
    
        static void init_meta();
    
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
