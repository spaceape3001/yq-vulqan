////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseEvent)

namespace yq::tachyon {

    ViewerCloseEvent::ViewerCloseEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerCloseEvent::~ViewerCloseEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCloseEvent::init_info()
    {
        auto w = writer<ViewerCloseEvent>();
        w.description("Viewer Close Event");
    }
}
