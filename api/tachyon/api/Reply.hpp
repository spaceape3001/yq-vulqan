////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Post.hpp>
#include <tachyon/typedef/reply.hpp>
#include <tachyon/typedef/request.hpp>

namespace yq::tachyon {
    class ReplyMeta : public PostMeta {
    public:
        template <typename C> class Writer;

        ReplyMeta(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };

    class Reply : public Post {
        YQ_OBJECT_META(ReplyMeta)
        YQ_OBJECT_DECLARE(Reply, Post)
        template <class> friend class Ref;
    public:
        
        const Request*  request() const;
        
        static void init_meta();
        
        struct Param {};        //< DEPRECATED
        
    protected:
        Reply(const RequestCPtr&, const Param&p={});    //< DEPRECATED;
    
        Reply(const Header&, const RequestCPtr&);
        Reply(const Reply&, const Header&);
        virtual ~Reply();
        
    private:
        RequestCPtr     m_request;
        
        Reply(const Reply&) = delete;
        Reply(Reply&&) = delete;
        Reply& operator=(const Reply&) = delete;
        Reply& operator=(Reply&&) = delete;
    };
}
