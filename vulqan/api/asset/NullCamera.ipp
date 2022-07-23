////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullCamera.hpp"

namespace yq {
    namespace asset {
        glm::dmat4  NullCamera::world2screen(const engine::CameraParams&cp) const 
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
    }
}
YQ_OBJECT_IMPLEMENT(yq::asset::NullCamera)
