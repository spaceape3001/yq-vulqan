////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/WindowRequest.hpp>

#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRequest)

namespace yq::tachyon {
    WindowRequest::WindowRequest(const Header&h) : Request(h)
    {
    }
    
    WindowRequest::WindowRequest(const WindowRequest& cp, const Header&h) : Request(cp, h)
    {
    }

    WindowRequest::~WindowRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowRequest::init_info()
    {
        auto w = writer<WindowRequest>();
        w.description("Window request base class");
    }
}
