////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraSpec.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    CameraSpec::CameraSpec()
    {
    }
    
    CameraSpec::~CameraSpec()
    {
    }
        
    void CameraSpec::init_meta()
    {
        auto w = writer<CameraSpec>();
        w.description("Camera Specification");
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::CameraSpec)
