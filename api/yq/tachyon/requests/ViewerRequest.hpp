////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/api/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerRequestInfo : public RequestInfo {
    public:
        ViewerRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerRequest : public Request, public ViewerBind {
        YQ_OBJECT_INFO(ViewerRequestInfo)
        YQ_OBJECT_DECLARE(ViewerRequest, Request)
    public:
    
        struct Param : public Request::Param {
        };
    
        ViewerRequest(ViewerID, const Param& p = {});
        ViewerRequest(const Viewer*, const Param& p = {});
        virtual ~ViewerRequest();
        static void init_info();
    };
}
