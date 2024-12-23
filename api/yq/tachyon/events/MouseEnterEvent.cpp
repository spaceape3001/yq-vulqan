////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEnterEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseEnterEvent::MouseEnterEvent(Window* w, const Param& p) : MouseEvent(w, p)
    {
    }
    
    MouseEnterEvent::MouseEnterEvent(WindowID w, const Param& p) : MouseEvent(w, p)
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

