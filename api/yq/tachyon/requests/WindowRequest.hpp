////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowRequestInfo : public RequestInfo {
    public:
        WindowRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowRequest : public Request, public ViewerBind {
        YQ_OBJECT_INFO(WindowRequestInfo)
        YQ_OBJECT_DECLARE(WindowRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        WindowRequest(Viewer*, const Param& p = {});
        virtual ~WindowRequest();
        static void init_info();
    };
}
