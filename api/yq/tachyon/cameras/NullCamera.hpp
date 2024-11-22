////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Camera.hpp>

namespace yq::tachyon {

    /*! \brief Null Camera
    
        The null camera has no relevant transformation.  It'll be a top-down
        projection.
    */
    class NullCamera : public Camera {
        YQ_TACHYON_DECLARE(NullCamera, Camera)
    public:
    
        //! Gets the world2screen matrix
        glm::dmat4  world2screen(const Values&) const override;
        NullCamera(const Param&p={});
        ~NullCamera();
        
        static void init_info();
    };
}
