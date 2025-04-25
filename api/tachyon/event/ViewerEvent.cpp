////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ViewerEvent.hpp>

#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerEvent)

namespace yq::tachyon {
    ViewerEvent::ViewerEvent(const Header&h) : Event(h)
    {
    }
    
    ViewerEvent::ViewerEvent(const ViewerEvent& cp, const Header&h) : Event(cp, h)
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
