////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Physics;
    using PhysicsPtr         = Ref<Physics>;
    using PhysicsCPtr        = Ref<const Physics>;

    struct PhysicsSnap;
    using PhysicsSnapPtr     = Ref<PhysicsSnap>;
    using PhysicsSnapCPtr    = Ref<const PhysicsSnap>;
    
    struct PhysicsData;
    using PhysicsDataPtr     = Ref<PhysicsData>;
    using PhysicsDataCPtr    = Ref<const PhysicsData>;

    template <class> class ID;
    using PhysicsID = ID<Physics>;
    
    class PhysicsTweak;
    using PhysicsTweakCPtr   = Ref<PhysicsTweak>;
    
    class PhysicsMeta;
}
