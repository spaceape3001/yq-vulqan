////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerMoveEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerMoveEvent)

namespace yq::tachyon {

    ViewerMoveEvent::ViewerMoveEvent(Viewer* v, const Vector2I& pos, const Param& p) : ViewerEvent(v, p), m_position(pos)
    {
    }
    
    ViewerMoveEvent::~ViewerMoveEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerMoveEvent::init_info()
    {
        auto w = writer<ViewerMoveEvent>();
        w.description("Viewer Move Event");
        w.property("x", &ViewerMoveEvent::x).description("Viewer Window's new x-position").tag(kTag_Log);
        w.property("y", &ViewerMoveEvent::y).description("Viewer Window's new y-position").tag(kTag_Log);
        w.property("position", &ViewerMoveEvent::position).description("Viewer Window's new position");
    }
    
    YQ_INVOKE(ViewerMoveEvent::init_info();)
}
