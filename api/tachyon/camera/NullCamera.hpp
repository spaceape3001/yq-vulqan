////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/camera/Camera.hpp>

namespace yq::tachyon {

    /*! \brief Null Camera
    
        The null camera has no relevant transformation.  It'll be a top-down
        projection.
    */
    class NullCamera : public Camera {
        YQ_OBJECT_DECLARE(NullCamera, Camera)
    public:
    
        //! Gets the world2screen matrix
        glm::dmat4  world2screen(const Params&) const override;
        NullCamera();
        ~NullCamera();
    };
}
