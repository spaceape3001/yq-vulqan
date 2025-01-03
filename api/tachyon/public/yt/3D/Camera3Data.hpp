////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/scene/CameraData.hpp>
#include <yt/typedef/camera3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Camera³Snap : public CameraSnap {
        //  This now comes from the spatial3....
        //Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
        
        Spatial³ID              m_spatial;
    };
    
    struct Camera³Data : public CameraData {
    };
}
