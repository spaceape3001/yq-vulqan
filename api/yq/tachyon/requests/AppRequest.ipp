////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppRequest.hpp"

#include <yq/post/RequestInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppRequest)

namespace yq::tachyon {
    AppRequestInfo::AppRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl) :
        post::RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppRequest::AppRequest(const Param& p) : post::Request(p)
    {
    }
    
    AppRequest::~AppRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_viewer_request()
    {
        {
            auto w = writer<AppRequest>();
            w.description("App request base class");
        }
    }
    
    YQ_INVOKE(reg_viewer_request();)
}
