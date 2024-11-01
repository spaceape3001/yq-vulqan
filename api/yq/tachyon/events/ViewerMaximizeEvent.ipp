////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerMaximizeEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerMaximizeEvent)

namespace yq::tachyon {

    ViewerMaximizeEvent::ViewerMaximizeEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerMaximizeEvent::~ViewerMaximizeEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerMaximizeEvent::init_info()
    {
        auto w = writer<ViewerMaximizeEvent>();
        w.description("Viewer Maximize Event");
    }
    
    YQ_INVOKE(ViewerMaximizeEvent::init_info();)
}
