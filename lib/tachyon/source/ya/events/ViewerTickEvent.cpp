////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/ViewerTickEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerTickEvent)

namespace yq::tachyon {

    ViewerTickEvent::ViewerTickEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerTickEvent::~ViewerTickEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerTickEvent::init_info()
    {
        auto w = writer<ViewerTickEvent>();
        w.description("Viewer Tick Event");
    }
}
