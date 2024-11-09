////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowReply.hpp"

#include <yq/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowReply)

namespace yq::tachyon {
    WindowReplyInfo::WindowReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl) :
        post::ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowReply::WindowReply(const post::RequestCPtr& rq, Viewer* v, const Param& p) : post::Reply(rq, p), ViewerBind(v)
    {
    }
    
    WindowReply::~WindowReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowReply::init_info()
    {
        auto w = writer<WindowReply>();
        w.description("Window reply base class");
    }
}
