////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/ViewerResumeEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerResumeEvent)

namespace yq::tachyon {

    ViewerResumeEvent::ViewerResumeEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerResumeEvent::~ViewerResumeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerResumeEvent::init_info()
    {
        auto w = writer<ViewerResumeEvent>();
        w.description("Viewer Resume Event");
    }
}