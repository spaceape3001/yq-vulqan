////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/ViewerRequest.hpp>

#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRequest)

namespace yq::tachyon {
    ViewerRequestInfo::ViewerRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerRequest::ViewerRequest(ViewerID v, const Param& p) : Request(p), ViewerBind(v)
    {
    }
    
    ViewerRequest::ViewerRequest(const Viewer* v, const Param& p) : Request(p), ViewerBind(v)
    {
    }

    ViewerRequest::~ViewerRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerRequest::init_info()
    {
        auto w = writer<ViewerRequest>();
        w.description("Viewer request base class");
    }
}
