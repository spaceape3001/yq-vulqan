////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowIconifyEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowIconifyEvent)

namespace yq::tachyon {

    WindowIconifyEvent::WindowIconifyEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowIconifyEvent::~WindowIconifyEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowIconifyEvent::init_info()
    {
        auto w = writer<WindowIconifyEvent>();
        w.description("Window Iconify Event");
    }
}
