////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerPauseEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerPauseEvent)

namespace yq::tachyon {

    ViewerPauseEvent::ViewerPauseEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerPauseEvent::~ViewerPauseEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerPauseEvent::init_info()
    {
        auto w = writer<ViewerPauseEvent>();
        w.description("Viewer Pause Event");
    }
}
