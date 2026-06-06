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
    class Force³;
    using Force³Ptr         = Ref<Force³>;
    using Force³CPtr        = Ref<const Force³>;

    struct Force³Snap;
    using Force³SnapPtr     = Ref<Force³Snap>;
    using Force³SnapCPtr    = Ref<const Force³Snap>;
    
    struct Force³Data;
    using Force³DataPtr     = Ref<Force³Data>;
    using Force³DataCPtr    = Ref<const Force³Data>;

    template <class> class ID;
    using Force³ID = ID<Force³>;
    
    class Force³Meta;
}
