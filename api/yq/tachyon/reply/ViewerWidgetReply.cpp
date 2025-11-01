////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/reply/ViewerWidgetReply.hpp>
#include <yq/tachyon/request/ViewerWidgetRequest.hpp>
#include <yq/tachyon/api/ReplyMetaWriter.hpp>

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

    void ViewerWidgetReply::init_meta()
    {
        auto w = writer<ViewerWidgetReply>();
        w.description("Viewer Widget Reply");
        w.property("response", &ViewerWidgetReply::response).tag(kTag_Log);
    }
}
