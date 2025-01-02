////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerEvent.hpp"

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerEvent)

namespace yq::tachyon {
    ViewerEventInfo::ViewerEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerEvent::ViewerEvent(Viewer* v, const Param& p) : Event(p), ViewerBind(v)
    {
    }
    
    ViewerEvent::ViewerEvent(ViewerID v, const Param& p) : Event(p), ViewerBind(v)
    {
    }
    
    ViewerEvent::~ViewerEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerEvent::init_info()
    {
        auto w = writer<ViewerEvent>();
        w.description("Viewer event base class");
    }
}
