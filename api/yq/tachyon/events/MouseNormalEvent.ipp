////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseNormalEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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
    
    YQ_INVOKE(MouseNormalEvent::init_info();)
}
