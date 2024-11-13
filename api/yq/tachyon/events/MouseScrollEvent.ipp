////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseScrollEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseScrollEvent::MouseScrollEvent(const Param& p) : MouseEvent(p), m_delta(p.delta)
    {
    }
    
    MouseScrollEvent::~MouseScrollEvent()
    {
    }

    void MouseScrollEvent::init_info()
    {
        auto w = writer<MouseScrollEvent>();
        w.description("Mouse Scroll Event");
        w.property("delta", &MouseScrollEvent::delta);
        w.property("dx", &MouseScrollEvent::delta_x).tag(kTag_Log);
        w.property("dy", &MouseScrollEvent::delta_y).tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseScrollEvent)

