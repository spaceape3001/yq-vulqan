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
    class Acceleration³;
    using Acceleration³Ptr         = Ref<Acceleration³>;
    using Acceleration³CPtr        = Ref<const Acceleration³>;

    struct Acceleration³Snap;
    using Acceleration³SnapPtr     = Ref<Acceleration³Snap>;
    using Acceleration³SnapCPtr    = Ref<const Acceleration³Snap>;
    
    struct Acceleration³Data;
    using Acceleration³DataPtr     = Ref<Acceleration³Data>;
    using Acceleration³DataCPtr    = Ref<const Acceleration³Data>;

    template <class> class ID;
    using Acceleration³ID = ID<Acceleration³>;
    
    class Acceleration³Meta;
}
