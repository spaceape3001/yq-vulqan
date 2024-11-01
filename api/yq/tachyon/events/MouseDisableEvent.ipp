////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDisableEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDisableEvent)

namespace yq::tachyon {

    MouseDisableEvent::MouseDisableEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
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
    
    YQ_INVOKE(MouseDisableEvent::init_info();)
}
