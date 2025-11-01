////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/AppReply.hpp>

#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppReply)

namespace yq::tachyon {
    AppReplyMeta::AppReplyMeta(std::string_view zName, ReplyMeta& base, const std::source_location& sl) :
        ReplyMeta(zName, base, sl)
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

    void AppReply::init_meta()
    {
        auto w = writer<AppReply>();
        w.description("App reply base class");
    }
}
