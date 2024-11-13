////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowDestroyEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowDestroyEvent)

namespace yq::tachyon {

    WindowDestroyEvent::WindowDestroyEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowDestroyEvent::~WindowDestroyEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowDestroyEvent::init_info()
    {
        auto w = writer<WindowDestroyEvent>();
        w.description("Window Destroy Event");
    }
}
