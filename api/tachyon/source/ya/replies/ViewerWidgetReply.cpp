////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/ViewerWidgetReply.hpp>
#include <ya/requests/ViewerWidgetRequest.hpp>
#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerWidgetReply)

namespace yq::tachyon {

    ViewerWidgetReply::ViewerWidgetReply(const ViewerWidgetRequestCPtr&rq, ViewerID v, Response r, const Param& p) :
        ViewerReply(rq, v, p), m_response(r)
    {
    }
    
    ViewerWidgetReply::ViewerWidgetReply(const ViewerWidgetRequestCPtr&rq, const Viewer* v, Response r, const Param& p) :
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
