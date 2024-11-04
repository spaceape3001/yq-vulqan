////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppReply.hpp"

#include <yq/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppReply)

namespace yq::tachyon {
    AppReplyInfo::AppReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl) :
        post::ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppReply::AppReply(const post::RequestCPtr& rq, const Param& p) : post::Reply(rq, p)
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
