////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/3DData.hpp>
#include <yt/api/TachyonData.hpp>
#include <yt/scene/CameraData.hpp>
#include <yt/typedef/camera3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Camera³Snap : public CameraSnap, public ③Snap {
        Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
    };
    
    struct Camera³Data : public CameraData, public ③Data {
    };
}

