////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullCamera.hpp"
#include <yt/scene/CameraInfoWriter.hpp>

namespace yq::tachyon {

/*
    glm::dmat4  NullCamera::world2screen(const Values&) const 
    {
        return {
            1.,  0.,  0.,  0.,
            0.,  1.,  0.,  0.,
            0.,  0.,  1.,  0.,
            0.,  0.,  0.,  1.
        };
    }
*/
    
    NullCamera::NullCamera(const Param&p) : Camera(p)
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

YQ_TACHYON_IMPLEMENT(yq::tachyon::NullCamera)
