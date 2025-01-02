////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraRequest.hpp"

#include <yt/msg/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraRequest)

namespace yq::tachyon {
    CameraRequestInfo::CameraRequestInfo(std::string_view zName, RequestInfo& base, const std::source_location& sl) :
        RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraRequest::CameraRequest(CameraID v, const Param& p) : Request(p), CameraBind(v)
    {
    }
    
    CameraRequest::CameraRequest(const Camera* v, const Param& p) : Request(p), CameraBind(v)
    {
    }

    CameraRequest::~CameraRequest()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraRequest::init_info()
    {
        auto w = writer<CameraRequest>();
        w.description("Camera request base class");
    }
}
