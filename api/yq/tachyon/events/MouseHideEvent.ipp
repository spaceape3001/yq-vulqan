////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseHideEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseHideEvent)

namespace yq::tachyon {

    MouseHideEvent::MouseHideEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    MouseHideEvent::~MouseHideEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseHideEvent::init_info()
    {
        auto w = writer<MouseHideEvent>();
        w.description("Mouse Hide Event");
    }
    
    YQ_INVOKE(MouseHideEvent::init_info();)
}
