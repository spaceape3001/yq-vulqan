////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/WindowReply.hpp>

#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowReply)

namespace yq::tachyon {
    WindowReplyInfo::WindowReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowReply::WindowReply(const RequestCPtr& rq, ViewerID v, const Param& p) : Reply(rq, p), ViewerBind(v)
    {
    }
    
    WindowReply::WindowReply(const RequestCPtr& rq, const Viewer* v, const Param& p) : Reply(rq, p), ViewerBind(v)
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
