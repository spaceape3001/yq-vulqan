////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEnterEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

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
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEnterEvent)

