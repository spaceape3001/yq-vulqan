////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowStateEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowStateEvent)

namespace yq::tachyon {

    WindowStateEvent::WindowStateEvent(Viewer* v, const ViewerState& st, const Param& p) : WindowEvent(v, p), m_state(st)
    {
    }
    
    WindowStateEvent::~WindowStateEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowStateEvent::init_info()
    {
        auto w = writer<WindowStateEvent>();
        w.description("Window State Event");
    }
}
