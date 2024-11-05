////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerIconifyEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerIconifyEvent)

namespace yq::tachyon {

    ViewerIconifyEvent::ViewerIconifyEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerIconifyEvent::~ViewerIconifyEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerIconifyEvent::init_info()
    {
        auto w = writer<ViewerIconifyEvent>();
        w.description("Viewer Iconify Event");
    }
}