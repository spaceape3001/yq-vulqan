////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRequest.hpp"

#include <yq/post/RequestInfoWriter.hpp>

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

    void ViewerRequest::init_info()
    {
        auto w = writer<ViewerRequest>();
        w.description("Viewer request base class");
    }
}
