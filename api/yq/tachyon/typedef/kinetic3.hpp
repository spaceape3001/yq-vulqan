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
    class Kinetic³;
    using Kinetic³Ptr      = Ref<Kinetic³>;
    using Kinetic³CPtr     = Ref<const Kinetic³>;

    struct Kinetic³Snap;
    using Kinetic³SnapPtr  = Ref<Kinetic³Snap>;
    using Kinetic³SnapCPtr = Ref<const Kinetic³Snap>;
    
    struct Kinetic³Data;
    using Kinetic³DataPtr  = Ref<Kinetic³Data>;
    using Kinetic³DataCPtr = Ref<const Kinetic³Data>;

    template <class> class ID;
    using Kinetic³ID = ID<Kinetic³>;

    class Kinetic³Meta;
}
