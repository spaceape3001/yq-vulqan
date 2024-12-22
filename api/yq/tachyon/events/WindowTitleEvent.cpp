////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowTitleEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowTitleEvent)

namespace yq::tachyon {

    WindowTitleEvent::WindowTitleEvent(Window* v, std::string_view szTitle, const Param& p) : WindowEvent(v, p), m_title(szTitle)
    {
    }
    
    WindowTitleEvent::~WindowTitleEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowTitleEvent::init_info()
    {
        auto w = writer<WindowTitleEvent>();
        w.description("Window Title Event");
        w.property("title", &WindowTitleEvent::title).description("Window Title");
    }
}
