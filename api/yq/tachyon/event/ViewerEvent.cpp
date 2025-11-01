////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/ViewerEvent.hpp>

#include <yq/tachyon/api/EventMetaWriter.hpp>

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

    void ViewerEvent::init_meta()
    {
        auto w = writer<ViewerEvent>();
        w.description("Viewer event base class");
    }
}
