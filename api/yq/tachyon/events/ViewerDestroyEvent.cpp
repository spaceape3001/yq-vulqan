////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerDestroyEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerDestroyEvent)

namespace yq::tachyon {

    ViewerDestroyEvent::ViewerDestroyEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerDestroyEvent::~ViewerDestroyEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerDestroyEvent::init_info()
    {
        auto w = writer<ViewerDestroyEvent>();
        w.description("Viewer Destroy Event");
    }
}
