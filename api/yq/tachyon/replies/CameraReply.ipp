////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraReply.hpp"

#include <yq/post/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraReply)

namespace yq::tachyon {
    CameraReplyInfo::CameraReplyInfo(std::string_view zName, post::ReplyInfo& base, const std::source_location& sl) :
        post::ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraReply::CameraReply(const post::RequestCPtr& rq, Camera* v, const Param& p) : post::Reply(rq, p), CameraBind(v)
    {
    }
    
    CameraReply::~CameraReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraReply::init_info()
    {
        auto w = writer<CameraReply>();
        w.description("Camera reply base class");
    }
}
