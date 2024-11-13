////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Request.hpp>

namespace yq::tachyon {
    class AppRequestInfo : public RequestInfo {
    public:
        AppRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppRequest : public Request {
        YQ_OBJECT_INFO(AppRequestInfo)
        YQ_OBJECT_DECLARE(AppRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        AppRequest(const Param& p = {});
        virtual ~AppRequest();
        static void init_info();
    };
}
