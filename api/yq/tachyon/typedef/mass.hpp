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
    class Mass;
    using MassPtr      = Ref<Mass>;
    using MassCPtr     = Ref<const Mass>;

    struct MassSnap;
    using MassSnapPtr  = Ref<MassSnap>;
    using MassSnapCPtr = Ref<const MassSnap>;
    
    struct MassData;
    using MassDataPtr  = Ref<MassData>;
    using MassDataCPtr = Ref<const MassData>;

    template <class> class ID;
    using MassID = ID<Mass>;
    
    class MassMeta;
}
