////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRestoreEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRestoreEvent)

namespace yq::tachyon {

    ViewerRestoreEvent::ViewerRestoreEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerRestoreEvent::~ViewerRestoreEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerRestoreEvent::init_info()
    {
        auto w = writer<ViewerRestoreEvent>();
        w.description("Viewer Restore Event");
    }
    
    YQ_INVOKE(ViewerRestoreEvent::init_info();)
}
