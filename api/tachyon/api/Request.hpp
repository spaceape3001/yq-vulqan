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

    class RequestInfo : public PostMeta {
    public:
        template <typename C> class Writer;

        RequestInfo(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };

    class Request : public Post {
        YQ_OBJECT_INFO(RequestInfo)
        YQ_OBJECT_DECLARE(Request, Post)
    public:
    
        static void init_info();

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
