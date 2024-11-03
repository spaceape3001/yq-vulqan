////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerStateEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerStateEvent)

namespace yq::tachyon {

    ViewerStateEvent::ViewerStateEvent(Viewer* v, const ViewerState& st, const Param& p) : ViewerEvent(v, p), m_state(st)
    {
    }
    
    ViewerStateEvent::~ViewerStateEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerStateEvent::init_info()
    {
        auto w = writer<ViewerStateEvent>();
        w.description("Viewer State Event");
    }
    
    YQ_INVOKE(ViewerStateEvent::init_info();)
}
