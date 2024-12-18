////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerReply.hpp"

#include <yq/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerReply)

namespace yq::tachyon {
    ViewerReplyInfo::ViewerReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl) :
        post::ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerReply::ViewerReply(const post::RequestCPtr& rq, Viewer* v, const Param& p) : post::Reply(rq, p), ViewerBind(v)
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
