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
    class Camera³;
    using Camera³Ptr      = Ref<Camera³>;
    using Camera³CPtr     = Ref<const Camera³>;

    struct Camera³Snap;
    using Camera³SnapPtr  = Ref<Camera³Snap>;
    using Camera³SnapCPtr = Ref<const Camera³Snap>;
    
    struct Camera³Data;
    using Camera³DataPtr  = Ref<Camera³Data>;
    using Camera³DataCPtr = Ref<const Camera³Data>;

    template <class> class ID;
    using Camera³ID = ID<Camera³>;

    class Camera³Info;
}
