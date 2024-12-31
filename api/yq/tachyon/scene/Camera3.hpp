////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Camera.hpp"
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class Camera3Info : public CameraInfo {
    };
    
    class Camera3 : public Camera {
        YQ_TACHYON_INFO(Camera3Info)
        YQ_TACHYON_SNAP(Camera3Snap)
        YQ_TACHYON_DATA(Camera3Data)
        YQ_TACHYON_DECLARE(Camera3, Camera)
    public:
    
        struct Param : public Camera::Param {
            // setting *ANY* of these creates a simple spatial (3D)
        
            Vector3D        position        = NAN;
            Quaternion3D    orientation     = NAN;
            Vector3D        scale           = NAN;
        };
    
        static void init_info();
    
        Camera3ID id() const { return Camera3ID(UniqueID::id()); }
    
    protected:
        Camera3(const Param&);
        ~Camera3();
        
        void snap(Camera3Snap&) const;
        
        Spatial3ID      m_spatial;
    };
}
