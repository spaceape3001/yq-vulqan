////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physics/state/DState32.hpp>
#include <yq/tachyon/api/3DData.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/KineticData.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    struct Kinetic³Snap : public KineticSnap, public ③Snap {
        physics::DState32       state;
    };
    
    struct Kinetic³Data : public KineticData, public ③Data {
    };
}

