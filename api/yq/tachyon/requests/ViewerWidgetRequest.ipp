////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerWidgetRequest.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>
#include <yq/tachyon/widget/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerWidgetRequest)

namespace yq::tachyon {

    ViewerWidgetRequest::ViewerWidgetRequest(Viewer* v, WidgetPtr w, const Param& p) : ViewerRequest(v, p), m_widget(w)
    {
    }
    
    ViewerWidgetRequest::~ViewerWidgetRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerWidgetRequest::init_info()
    {
        auto w = writer<ViewerWidgetRequest>();
        w.description("Viewer Widget Request");
    }
}
