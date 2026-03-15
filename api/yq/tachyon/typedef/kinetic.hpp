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
    class Kinetic;
    using KineticPtr         = Ref<Kinetic>;
    using KineticCPtr        = Ref<const Kinetic>;

    struct KineticSnap;
    using KineticSnapPtr     = Ref<KineticSnap>;
    using KineticSnapCPtr    = Ref<const KineticSnap>;
    
    struct KineticData;
    using KineticDataPtr     = Ref<KineticData>;
    using KineticDataCPtr    = Ref<const KineticData>;

    template <class> class ID;
    using KineticID = ID<Kinetic>;
    
    class KineticMeta;
}
