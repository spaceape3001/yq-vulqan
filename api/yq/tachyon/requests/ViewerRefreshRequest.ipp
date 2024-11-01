////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRefreshRequest.hpp"
#include <yq/post/RequestInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRefreshRequest)

namespace yq::tachyon {

    ViewerRefreshRequest::ViewerRefreshRequest(Viewer* v, const Param& p) : ViewerRequest(v, p)
    {
    }
    
    ViewerRefreshRequest::~ViewerRefreshRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerRefreshRequest::init_info()
    {
        {
            auto w = writer<ViewerRefreshRequest>();
            w.description("Viewer Refresh Request");
        }
    }
    
    YQ_INVOKE(ViewerRefreshRequest::init_info();)
}
