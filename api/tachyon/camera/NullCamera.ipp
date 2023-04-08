////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NullCamera.hpp"

namespace yq {
    namespace tachyon {
        glm::dmat4  NullCamera::world2screen(const Params&) const 
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
YQ_OBJECT_IMPLEMENT(yq::tachyon::NullCamera)
