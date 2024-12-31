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
    class Light3;
    using Light3Ptr      = Ref<Light3>;
    using Light3CPtr     = Ref<const Light3>;

    struct Light3Snap;
    using Light3SnapPtr  = Ref<Light3Snap>;
    using Light3SnapCPtr = Ref<const Light3Snap>;
    
    struct Light3Data;
    using Light3DataPtr  = Ref<Light3Data>;
    using Light3DataCPtr = Ref<const Light3Data>;

    template <class> class ID;
    using Light3ID = ID<Light3>;
}
