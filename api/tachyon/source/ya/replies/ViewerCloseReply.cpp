////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/ViewerCloseReply.hpp>
#include <ya/requests/ViewerCloseRequest.hpp>
#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseReply)

namespace yq::tachyon {

    ViewerCloseReply::ViewerCloseReply(const RequestCPtr&rq, ViewerID v, Response r, const Param& p) :
        ViewerReply(rq, v, p), m_response(r)
    {
    }
    
    ViewerCloseReply::ViewerCloseReply(const RequestCPtr&rq, const Viewer* v, Response r, const Param& p) :
        ViewerReply(rq, v, p), m_response(r)
    {
    }

    ViewerCloseReply::~ViewerCloseReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCloseReply::init_info()
    {
        auto w = writer<ViewerCloseReply>();
        w.description("Viewer Close Reply");
        w.property("response", &ViewerCloseReply::response).tag(kTag_Log);
    }
}
