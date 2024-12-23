////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseReply.hpp"
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/api/ReplyInfoWriter.hpp>

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
