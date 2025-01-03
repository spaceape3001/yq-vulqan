////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MouseHideEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseHideEvent)

namespace yq::tachyon {

    MouseHideEvent::MouseHideEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    MouseHideEvent::~MouseHideEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseHideEvent::init_info()
    {
        auto w = writer<MouseHideEvent>();
        w.description("Mouse Restore Event");
    }
}
