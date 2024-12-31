////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Camera3Snap : public CameraSnap {
        //  This now comes from the spatial3....
        //Tensor44D   view        = IDENTITY;
        Tensor44D   projection  = IDENTITY;
        Rectangle2D screen      = Rectangle2D(ZERO, ONE);
        
        Spatial3ID              m_spatial;
    };
    
    struct Camera3Data : public CameraData {
    };
}

