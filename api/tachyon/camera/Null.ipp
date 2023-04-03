////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Null.hpp"

namespace yq {
    namespace camera {
        glm::dmat4  Null::world2screen(const Params&) const 
        {
            return {
                1.,  0.,  0.,  0.,
                0.,  1.,  0.,  0.,
                0.,  0.,  1.,  0.,
                0.,  0.,  0.,  1.
            };
        }
        
        Null::Null()
        {
        }
        
        Null::~Null()
        {
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::camera::Null)
