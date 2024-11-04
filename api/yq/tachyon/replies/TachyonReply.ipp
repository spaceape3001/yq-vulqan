////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonReply.hpp"

#include <yq/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonReply)

namespace yq::tachyon {
    TachyonReplyInfo::TachyonReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl) :
        post::ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    TachyonReply::TachyonReply(const post::RequestCPtr& rq, Tachyon* v, const Param& p) : post::Reply(rq, p), TachyonBind(v)
    {
    }
    
    TachyonReply::~TachyonReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TachyonReply::init_info()
    {
        auto w = writer<TachyonReply>();
        w.description("Tachyon reply base class");
    }
}
