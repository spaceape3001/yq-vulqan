////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerFocusEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerFocusEvent)

namespace yq::tachyon {

    ViewerFocusEvent::ViewerFocusEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerFocusEvent::~ViewerFocusEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerFocusEvent::init_info()
    {
        auto w = writer<ViewerFocusEvent>();
        w.description("Viewer Focus Event");
    }
}
