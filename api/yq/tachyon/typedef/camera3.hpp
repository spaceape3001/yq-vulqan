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
    class Camera3;
    using Camera3Ptr      = Ref<Camera3>;
    using Camera3CPtr     = Ref<const Camera3>;

    struct Camera3Snap;
    using Camera3SnapPtr  = Ref<Camera3Snap>;
    using Camera3SnapCPtr = Ref<const Camera3Snap>;
    
    struct Camera3Data;
    using Camera3DataPtr  = Ref<Camera3Data>;
    using Camera3DataCPtr = Ref<const Camera3Data>;

    template <class> class ID;
    using Camera3ID = ID<Camera3>;
}
