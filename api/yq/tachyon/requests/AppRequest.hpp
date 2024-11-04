////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Request.hpp>

namespace yq::tachyon {
    class AppRequestInfo : public post::RequestInfo {
    public:
        AppRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppRequest : public post::Request {
        YQ_OBJECT_INFO(AppRequestInfo)
        YQ_OBJECT_DECLARE(AppRequest, post::Request)
    public:
    
        struct Param : public post::Request::Param {
        };
    
        AppRequest(const Param& p = {});
        virtual ~AppRequest();
        static void init_info();
    };
}
