////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/ViewerReply.hpp>

#include <tachyon/api/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerReply)

namespace yq::tachyon {
    ViewerReply::ViewerReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    ViewerReply::ViewerReply(const ViewerReply&cp, const Header&h) : Reply(cp, h)
    {
    }

    ViewerReply::~ViewerReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerReply::init_info()
    {
        auto w = writer<ViewerReply>();
        w.description("Viewer reply base class");
    }
}
