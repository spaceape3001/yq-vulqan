////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/physics.hpp>

namespace yq::tachyon {
    class PhysicsSnap : public ModelSnap {
        YQ_OBJECT_DECLARE(PhysicsSnap, ModelSnap)
    public:
        bool    enabled = false;    //<< thinking about moving this to model/tachyon

        PhysicsSnap();
        virtual ~PhysicsSnap();
        static void init_meta();
    };
    
    class PhysicsData : public ModelData {
        YQ_OBJECT_DECLARE(PhysicsData, ModelData);
    public:
        PhysicsData();
        virtual ~PhysicsData();
        static void init_meta();
    };
}
