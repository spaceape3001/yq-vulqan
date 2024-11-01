////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseLeaveEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    MouseLeaveEvent::MouseLeaveEvent(const Param& p) : MouseEvent(p)
    {
    }
    
    MouseLeaveEvent::~MouseLeaveEvent()
    {
    }

    void MouseLeaveEvent::init_info()
    {
        auto w = writer<MouseLeaveEvent>();
        w.description("Mouse Leave Event");
    }
    
    YQ_INVOKE(MouseLeaveEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseLeaveEvent)

