////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerWidgetReply.hpp"
#include <yq/tachyon/requests/ViewerWidgetRequest.hpp>
#include <yq/tachyon/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerWidgetReply)

namespace yq::tachyon {

    ViewerWidgetReply::ViewerWidgetReply(const ViewerWidgetRequestCPtr&rq, Viewer* v, Response r, const Param& p) :
        ViewerReply(rq, v, p), m_response(r)
    {
    }
    
    ViewerWidgetReply::~ViewerWidgetReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerWidgetReply::init_info()
    {
        auto w = writer<ViewerWidgetReply>();
        w.description("Viewer Widget Reply");
        w.property("response", &ViewerWidgetReply::response).tag(kTag_Log);
    }
}
