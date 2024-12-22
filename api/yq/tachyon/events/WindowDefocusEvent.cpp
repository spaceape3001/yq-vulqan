////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowDefocusEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowDefocusEvent)

namespace yq::tachyon {

    WindowDefocusEvent::WindowDefocusEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowDefocusEvent::~WindowDefocusEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowDefocusEvent::init_info()
    {
        auto w = writer<WindowDefocusEvent>();
        w.description("Window Defocus Event");
    }
}
