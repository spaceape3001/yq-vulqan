////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRestoreEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRestoreEvent)

namespace yq::tachyon {

    WindowRestoreEvent::WindowRestoreEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowRestoreEvent::~WindowRestoreEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowRestoreEvent::init_info()
    {
        auto w = writer<WindowRestoreEvent>();
        w.description("Window Restore Event");
    }
}
