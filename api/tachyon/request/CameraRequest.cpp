////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/request/CameraRequest.hpp>
#include <tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraRequest)

namespace yq::tachyon {
    CameraRequest::CameraRequest(const Header& h) : Request(h)
    {
    }
    
    CameraRequest::CameraRequest(const CameraRequest&cp, const Header&h) : Request(cp, h)
    {
    }

    CameraRequest::~CameraRequest()
    {
    }
    
    void CameraRequest::init_meta()
    {
        auto w = writer<CameraRequest>();
        w.abstract();
        w.description("Camera Request");
    }
}
