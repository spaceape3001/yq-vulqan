////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppReply.hpp"

#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppReply)

namespace yq::tachyon {
    AppReplyInfo::AppReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppReply::AppReply(const RequestCPtr& rq, const Param& p) : Reply(rq, p)
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
