////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/ViewerReply.hpp>

#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerReply)

namespace yq::tachyon {
    ViewerReplyInfo::ViewerReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerReply::ViewerReply(const RequestCPtr& rq, ViewerID v, const Param& p) : Reply(rq, p), ViewerBind(v)
    {
    }
    
    ViewerReply::ViewerReply(const RequestCPtr& rq, const Viewer* v, const Param& p) : Reply(rq, p), ViewerBind(v)
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
