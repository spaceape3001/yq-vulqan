////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseRequest.hpp"
#include <yq/post/RequestInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseRequest)

namespace yq::tachyon {

    ViewerCloseRequest::ViewerCloseRequest(Viewer* v, const Param& p) : ViewerRequest(v, p)
    {
    }
    
    ViewerCloseRequest::~ViewerCloseRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_viewer_close_request()
    {
        {
            auto w = writer<ViewerCloseRequest>();
            w.description("Viewer Close Request");
        }
    }
    
    YQ_INVOKE(reg_viewer_close_request();)
}
