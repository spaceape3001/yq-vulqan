////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/dim/3DData.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Camera³Snap : public CameraSnap, public ③Snap {
        YQ_OBJECT_DECLARE(Camera³Snap, CameraSnap)
    public:
    
        //  This is to apply any corrections to get the coordinate system correct... 
        //  the spatial will be on top of this.
        Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
        
        Camera³Snap();
        ~Camera³Snap();
        
        static void init_meta();
    };
    
    class Camera³Data : public CameraData, public ③Data {
        YQ_OBJECT_DECLARE(Camera³Data, CameraData)
    public:
        Camera³Data();
        ~Camera³Data();
        
        static void init_meta();
    };
}

