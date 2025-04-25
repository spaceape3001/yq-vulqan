////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/3DData.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Camera³Snap : public CameraSnap, public ③Snap {
        //  This is to apply any corrections to get the coordinate system correct... 
        //  the spatial will be on top of this.
        //Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
    };
    
    struct Camera³Data : public CameraData, public ③Data {
    };
}

