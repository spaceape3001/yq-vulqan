////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRequest.hpp"

#include <yq/post/RequestInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRequest)

namespace yq::tachyon {
    ViewerRequestInfo::ViewerRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl) :
        post::RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerRequest::ViewerRequest(Viewer* v, const Param& p) : post::Request(p), ViewerBind(v)
    {
    }
    
    ViewerRequest::~ViewerRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_viewer_request()
    {
        {
            auto w = writer<ViewerRequest>();
            w.description("Viewer request base class");
        }
    }
    
    YQ_INVOKE(reg_viewer_request();)
}
