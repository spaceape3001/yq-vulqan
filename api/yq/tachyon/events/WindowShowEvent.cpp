////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowShowEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowShowEvent)

namespace yq::tachyon {

    WindowShowEvent::WindowShowEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowShowEvent::~WindowShowEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowShowEvent::init_info()
    {
        auto w = writer<WindowShowEvent>();
        w.description("Window Show Event");
    }
}
