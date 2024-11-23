////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRefreshRequest.hpp"
#include <yq/tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRefreshRequest)

namespace yq::tachyon {

    WindowRefreshRequest::WindowRefreshRequest(ViewerID v, const Param& p) : WindowRequest(v, p)
    {
    }
    
    WindowRefreshRequest::WindowRefreshRequest(const Viewer* v, const Param& p) : WindowRequest(v, p)
    {
    }

    WindowRefreshRequest::~WindowRefreshRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowRefreshRequest::init_info()
    {
        auto w = writer<WindowRefreshRequest>();
        w.description("Window Refresh Request");
    }
}
