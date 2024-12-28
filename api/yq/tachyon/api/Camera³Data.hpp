////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/typedef/camera³.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Camera³Snap : public CameraSnap {
        Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
    };
    
    struct Camera³Data : public CameraData {
    };
}

