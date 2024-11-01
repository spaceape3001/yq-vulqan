////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseMoveEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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
    
    YQ_INVOKE(MouseMoveEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseMoveEvent)

