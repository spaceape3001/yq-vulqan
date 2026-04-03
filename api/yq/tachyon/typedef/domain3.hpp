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
    class Domain³;
    using Domain³Ptr      = Ref<Domain³>;
    using Domain³CPtr     = Ref<const Domain³>;

    struct Domain³Snap;
    using Domain³SnapPtr  = Ref<Domain³Snap>;
    using Domain³SnapCPtr = Ref<const Domain³Snap>;
    
    struct Domain³Data;
    using Domain³DataPtr  = Ref<Domain³Data>;
    using Domain³DataCPtr = Ref<const Domain³Data>;

    template <class> class ID;
    using Domain³ID = ID<Domain³>;
    class Domain³Meta;
}
