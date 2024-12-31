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
    class Scene3;
    using Scene3Ptr      = Ref<Scene3>;
    using Scene3CPtr     = Ref<const Scene3>;

    struct Scene3Snap;
    using Scene3SnapPtr  = Ref<Scene3Snap>;
    using Scene3SnapCPtr = Ref<const Scene3Snap>;
    
    struct Scene3Data;
    using Scene3DataPtr  = Ref<Scene3Data>;
    using Scene3DataCPtr = Ref<const Scene3Data>;

    template <class> class ID;
    using Scene3ID = ID<Scene3>;
}
