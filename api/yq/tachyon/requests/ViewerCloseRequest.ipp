////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseRequest.hpp"
#include <yq/tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseRequest)

namespace yq::tachyon {

    ViewerCloseRequest::ViewerCloseRequest(Viewer* v, const Param& p) : ViewerRequest(v, p)
    {
    }
    
    ViewerCloseRequest::~ViewerCloseRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCloseRequest::init_info()
    {
        auto w = writer<ViewerCloseRequest>();
        w.description("Viewer Close Request");
    }
}
