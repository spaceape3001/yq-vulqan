////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Post.hpp>
#include <tachyon/typedef/request.hpp>
#include <tachyon/api/TypedID.hpp>

namespace yq::tachyon {

    class RequestMeta : public PostMeta {
    public:
        template <typename C> class Writer;

        RequestMeta(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };

    class Request : public Post {
        YQ_OBJECT_INFO(RequestMeta)
        YQ_OBJECT_DECLARE(Request, Post)
    public:
    
        static void init_meta();

        struct Param {}; //< DEPRECATED
        
    protected:
        Request(const Param&p={}); //< DEPRECATED
        Request(const Header&);
        Request(const Request&, const Header&);
        virtual ~Request();
        
    private:
        Request(Request&&) = delete;
        Request(const Request&) = delete;
        Request& operator=(const Request&) = delete;
        Request& operator=(Request&&) = delete;
    };
}
