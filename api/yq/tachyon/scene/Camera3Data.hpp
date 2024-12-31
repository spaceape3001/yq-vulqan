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
        //  This now comes from the spatial³....
        //Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
        
        Spatial³ID              m_spatial;
    };
    
    struct Camera³Data : public CameraData {
    };
}

