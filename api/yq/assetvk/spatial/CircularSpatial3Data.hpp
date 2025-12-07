////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3Data.hpp>

namespace yq::tachyon {
    struct CircularSpatial³Snap : public Spatial³Snap {
        Radian          angle       = 0._rad;
        bool            locked      = false;
        Vector3D        origin      = ZERO;
        Second          period      = 0._s;
        double          radius      = 0.;
        unit::Degree3D  rotation      = ZERO;
    };
}
