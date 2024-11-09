////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowShowEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowShowEvent)

namespace yq::tachyon {

    WindowShowEvent::WindowShowEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
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
