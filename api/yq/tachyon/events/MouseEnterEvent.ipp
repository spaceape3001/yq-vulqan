////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEnterEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    MouseEnterEvent::MouseEnterEvent(const Param& p) : MouseEvent(p)
    {
    }
    
    MouseEnterEvent::~MouseEnterEvent()
    {
    }

    void MouseEnterEvent::init_info()
    {
        auto w = writer<MouseEnterEvent>();
        w.description("Mouse Enter Event");
    }
    
    YQ_INVOKE(MouseEnterEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEnterEvent)

