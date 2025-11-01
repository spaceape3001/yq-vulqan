////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerScreenshotRequest.hpp"
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerScreenshotRequest)

namespace yq::tachyon {

    ViewerScreenshotRequest::ViewerScreenshotRequest(const Header&h) : ViewerRequest(h)
    {
    }

    ViewerScreenshotRequest::ViewerScreenshotRequest(const ViewerScreenshotRequest& cp, const Header& h) : ViewerRequest(cp, h)
    {
    }
    
    ViewerScreenshotRequest::~ViewerScreenshotRequest()
    {
    }

    PostCPtr    ViewerScreenshotRequest::clone(rebind_k, const Header&h) const 
    {
        return new ViewerScreenshotRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerScreenshotRequest::init_meta()
    {
        auto w = writer<ViewerScreenshotRequest>();
        w.description("ViewerScreenshot Request");
    }
}
