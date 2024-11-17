////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRefreshRequest.hpp"
#include <yq/tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRefreshRequest)

namespace yq::tachyon {

    WindowRefreshRequest::WindowRefreshRequest(Viewer* v, const Param& p) : WindowRequest(v, p)
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
