////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseNormalEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseNormalEvent)

namespace yq::tachyon {

    MouseNormalEvent::MouseNormalEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
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
