////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDisableEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

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
}
