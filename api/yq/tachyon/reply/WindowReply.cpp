////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/reply/WindowReply.hpp>
#include <yq/tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowReply)

namespace yq::tachyon {
    WindowReply::WindowReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    WindowReply::WindowReply(const WindowReply& cp, const Header&h) : Reply(cp, h)
    {
    }

    WindowReply::~WindowReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowReply::init_meta()
    {
        auto w = writer<WindowReply>();
        w.description("Window reply base class");
    }
}
