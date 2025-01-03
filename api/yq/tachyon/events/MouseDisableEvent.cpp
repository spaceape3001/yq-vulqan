////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDisableEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDisableEvent)

namespace yq::tachyon {

    MouseDisableEvent::MouseDisableEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    MouseDisableEvent::~MouseDisableEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseDisableEvent::init_info()
    {
        auto w = writer<MouseDisableEvent>();
        w.description("Mouse Disable Event");
    }
}
