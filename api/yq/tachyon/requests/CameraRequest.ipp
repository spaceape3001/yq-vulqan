////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraRequest.hpp"

#include <yq/post/RequestInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraRequest)

namespace yq::tachyon {
    CameraRequestInfo::CameraRequestInfo(std::string_view zName, post::RequestInfo& base, const std::source_location& sl) :
        post::RequestInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraRequest::CameraRequest(Camera* v, const Param& p) : post::Request(p), CameraBind(v)
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
