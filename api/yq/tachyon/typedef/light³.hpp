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
    class Light³;
    using Light³Ptr      = Ref<Light³>;
    using Light³CPtr     = Ref<const Light³>;

    struct Light³Snap;
    using Light³SnapPtr  = Ref<Light³Snap>;
    using Light³SnapCPtr = Ref<const Light³Snap>;
    
    struct Light³Data;
    using Light³DataPtr  = Ref<Light³Data>;
    using Light³DataCPtr = Ref<const Light³Data>;

    template <class> class ID;
    using Light³ID = ID<Light³>;
}
