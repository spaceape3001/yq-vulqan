////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCloseRequest.hpp"
#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCloseRequest)

namespace yq::tachyon {

    WindowCloseRequest::WindowCloseRequest(WindowID v, const Param& p) : WindowRequest(v, p)
    {
    }
    
    WindowCloseRequest::WindowCloseRequest(const Window* v, const Param& p) : WindowRequest(v, p)
    {
    }

    WindowCloseRequest::~WindowCloseRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCloseRequest::init_info()
    {
        auto w = writer<WindowCloseRequest>();
        w.description("Window Close Request");
    }
}
