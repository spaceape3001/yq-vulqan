////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Post.hpp>
#include <yq/tachyon/typedef/request.hpp>

namespace yq::tachyon {

    class RequestInfo : public PostInfo {
    public:
        template <typename C> class Writer;

        RequestInfo(std::string_view zName, PostInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class Request : public Post {
        YQ_OBJECT_INFO(RequestInfo)
        YQ_OBJECT_DECLARE(Request, Post)
    public:
    
        struct Param : public Post::Param {
        };
        
        static void init_info();
        
    protected:
        Request(const Param& p={});
        virtual ~Request();
    };
}
