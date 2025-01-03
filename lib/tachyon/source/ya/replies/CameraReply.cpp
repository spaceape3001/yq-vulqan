////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/replies/CameraReply.hpp>

#include <yt/msg/ReplyInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraReply)

namespace yq::tachyon {
    CameraReplyInfo::CameraReplyInfo(std::string_view zName, ReplyInfo& base, const std::source_location& sl) :
        ReplyInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraReply::CameraReply(const RequestCPtr& rq, CameraID v, const Param& p) : Reply(rq, p), CameraBind(v)
    {
    }
    
    CameraReply::CameraReply(const RequestCPtr& rq, const Camera* v, const Param& p) : Reply(rq, p), CameraBind(v)
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
