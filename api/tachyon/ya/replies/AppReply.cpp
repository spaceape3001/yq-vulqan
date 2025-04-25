////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/AppReply.hpp>

#include <tachyon/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppReply)

namespace yq::tachyon {
    AppReplyInfo::AppReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppReply::AppReply(const Header& h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }

    AppReply::AppReply(const AppReply& cp, const Header& h) : Reply(cp, h)
    {
    }


    AppReply::~AppReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppReply::init_info()
    {
        auto w = writer<AppReply>();
        w.description("App reply base class");
    }
}
