////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/requests/ViewerWidgetRequest.hpp>
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/tachyon/widget/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerWidgetRequest)

namespace yq::tachyon {

    ViewerWidgetRequest::ViewerWidgetRequest(ViewerID v, WidgetPtr w, const Param& p) : ViewerRequest(v, p), m_widget(w)
    {
    }
    
    ViewerWidgetRequest::ViewerWidgetRequest(const Viewer* v, WidgetPtr w, const Param& p) : ViewerRequest(v, p), m_widget(w)
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
