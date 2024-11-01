////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerScaleEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerScaleEvent)

namespace yq::tachyon {

    ViewerScaleEvent::ViewerScaleEvent(Viewer* v, const Vector2F& sc, const Param& p) : ViewerEvent(v, p), m_scale(sc)
    {
    }
    
    ViewerScaleEvent::~ViewerScaleEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerScaleEvent::init_info()
    {
        auto w = writer<ViewerScaleEvent>();
        w.description("Viewer Scale Event");
        w.property("x", &ViewerScaleEvent::x).description("Viewer Window's new x-scale").tag(kTag_Log);
        w.property("y", &ViewerScaleEvent::y).description("Viewer Window's new y-scale").tag(kTag_Log);
        w.property("scale", &ViewerScaleEvent::scale).description("Viewer Window's new scale");
    }
    
    YQ_INVOKE(ViewerScaleEvent::init_info();)
}
