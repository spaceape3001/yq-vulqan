////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/reply/CameraReply.hpp>

#include <tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraReply)

namespace yq::tachyon {

    CameraReply::CameraReply(const Header&h, const RequestCPtr& rq) : Reply(h, rq)
    {
    }
    
    CameraReply::CameraReply(const CameraReply& cp, const Header& h) : Reply(cp, h)
    {
    }

    CameraReply::~CameraReply()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraReply::init_meta()
    {
        auto w = writer<CameraReply>();
        w.description("Camera reply base class");
    }
}
