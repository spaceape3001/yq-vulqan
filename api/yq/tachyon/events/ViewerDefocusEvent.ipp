////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerDefocusEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerDefocusEvent)

namespace yq::tachyon {

    ViewerDefocusEvent::ViewerDefocusEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerDefocusEvent::~ViewerDefocusEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerDefocusEvent::init_info()
    {
        auto w = writer<ViewerDefocusEvent>();
        w.description("Viewer Defocus Event");
    }
}
