////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Request.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowRequestInfo : public post::RequestInfo {
    public:
        WindowRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowRequest : public post::Request, public ViewerBind {
        YQ_OBJECT_INFO(WindowRequestInfo)
        YQ_OBJECT_DECLARE(WindowRequest, post::Request)
    public:
    
        struct Param : public post::Request::Param {
        };
    
        WindowRequest(Viewer*, const Param& p = {});
        virtual ~WindowRequest();
        static void init_info();
    };
}
