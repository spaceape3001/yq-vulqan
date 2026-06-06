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
    class Collision³;
    using Collision³Ptr         = Ref<Collision³>;
    using Collision³CPtr        = Ref<const Collision³>;

    struct Collision³Snap;
    using Collision³SnapPtr     = Ref<Collision³Snap>;
    using Collision³SnapCPtr    = Ref<const Collision³Snap>;
    
    struct Collision³Data;
    using Collision³DataPtr     = Ref<Collision³Data>;
    using Collision³DataCPtr    = Ref<const Collision³Data>;

    template <class> class ID;
    using Collision³ID = ID<Collision³>;
    
    class Collision³Meta;
}
