////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseMoveEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseMoveEvent::MouseMoveEvent(const Param& p) : MouseEvent(p)
    {
    }
    
    MouseMoveEvent::~MouseMoveEvent()
    {
    }

    void MouseMoveEvent::init_info()
    {
        auto w = writer<MouseMoveEvent>();
        w.description("Mouse Move Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseMoveEvent)

