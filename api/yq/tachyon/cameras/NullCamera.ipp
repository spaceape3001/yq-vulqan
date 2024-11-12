////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullCamera.hpp"
#include <yq/tachyon/camera/CameraInfoWriter.hpp>

namespace yq::tachyon {
    glm::dmat4  NullCamera::world2screen(const Values&) const 
    {
        return {
            1.,  0.,  0.,  0.,
            0.,  1.,  0.,  0.,
            0.,  0.,  1.,  0.,
            0.,  0.,  0.,  1.
        };
    }
    
    NullCamera::NullCamera()
    {
    }
    
    NullCamera::~NullCamera()
    {
    }

    void NullCamera::init_info()
    {
        auto w = writer<NullCamera>();
        w.description("Null camera, (Identity transform)");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::NullCamera)
