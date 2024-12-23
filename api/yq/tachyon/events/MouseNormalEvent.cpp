////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseNormalEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseNormalEvent)

namespace yq::tachyon {

    MouseNormalEvent::MouseNormalEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    MouseNormalEvent::~MouseNormalEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseNormalEvent::init_info()
    {
        auto w = writer<MouseNormalEvent>();
        w.description("Mouse Restore Event");
    }
}
