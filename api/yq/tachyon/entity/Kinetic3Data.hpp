////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physics/state/DState32.hpp>
#include <yq/tachyon/api/dim/3DData.hpp>
#include <yq/tachyon/entity/KineticData.hpp>
#include <yq/tachyon/typedef/kinetic3.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    class Kinetic³Snap : public KineticSnap, public ③Snap {
        YQ_OBJECT_DECLARE(Kinetic³Snap, KineticSnap)
    public:
        physics::DState32       state;
        
        Kinetic³Snap();
        virtual ~Kinetic³Snap();
        static void init_meta();
    };
    
    class Kinetic³Data : public KineticData, public ③Data {
        YQ_OBJECT_DECLARE(Kinetic³Data, KineticData)
    public:
    
        Kinetic³Data();
        virtual ~Kinetic³Data();
        static void init_meta();
    };
}

