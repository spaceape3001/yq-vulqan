////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRefreshRequest.hpp"
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRefreshRequest)

namespace yq::tachyon {

    WindowRefreshRequest::WindowRefreshRequest(WindowID v, const Param& p) : WindowRequest(v, p)
    {
    }
    
    WindowRefreshRequest::WindowRefreshRequest(const Window* v, const Param& p) : WindowRequest(v, p)
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
