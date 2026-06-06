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
    class Moment³;
    using Moment³Ptr         = Ref<Moment³>;
    using Moment³CPtr        = Ref<const Moment³>;

    struct Moment³Snap;
    using Moment³SnapPtr     = Ref<Moment³Snap>;
    using Moment³SnapCPtr    = Ref<const Moment³Snap>;
    
    struct Moment³Data;
    using Moment³DataPtr     = Ref<Moment³Data>;
    using Moment³DataCPtr    = Ref<const Moment³Data>;

    template <class> class ID;
    using Moment³ID = ID<Moment³>;
    
    class Moment³Meta;
}
