////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseReply.hpp"
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/post/ReplyInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseReply)

namespace yq::tachyon {

    ViewerCloseReply::ViewerCloseReply(const ViewerCloseRequestCPtr&rq, Viewer*v, Response r, const Param& p) :
        ViewerReply(rq, v, p), m_response(r)
    {
    }
    
    ViewerCloseReply::~ViewerCloseReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_viewer_close_reply()
    {
        {
            auto w = writer<ViewerCloseReply>();
            w.description("Viewer Close Reply");
            w.property("response", &ViewerCloseReply::response);
        }
    }
    
    YQ_INVOKE(reg_viewer_close_reply();)
}
