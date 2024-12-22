////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRequest.hpp"

#include <yq/tachyon/api/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRequest)

namespace yq::tachyon {
    WindowRequestInfo::WindowRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowRequest::WindowRequest(WindowID v, const Param& p) : Request(p), WindowBind(v)
    {
    }
    
    WindowRequest::WindowRequest(const Window* v, const Param& p) : Request(p), WindowBind(v)
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
