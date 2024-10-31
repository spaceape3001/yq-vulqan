////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseEvent)

namespace yq::tachyon {

    ViewerCloseEvent::ViewerCloseEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
    {
    }
    
    ViewerCloseEvent::~ViewerCloseEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_viewer_close_request()
    {
        {
            auto w = writer<ViewerCloseEvent>();
            w.description("Viewer Close Event");
        }
    }
    
    YQ_INVOKE(reg_viewer_close_request();)
}
