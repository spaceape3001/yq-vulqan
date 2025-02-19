////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/IOReply.hpp>

#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IOReply)

namespace yq::tachyon {

    IOReply::IOReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    IOReply::IOReply(const IOReply& cp, const Header& h) : Reply(cp, h)
    {
    }

    IOReply::~IOReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void IOReply::init_info()
    {
        auto w = writer<IOReply>();
        w.description("IO reply base class");
    }
}
