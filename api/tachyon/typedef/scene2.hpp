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
    class Scene2;
    using Scene2Ptr      = Ref<Scene2>;
    using Scene2CPtr     = Ref<const Scene2>;

    struct Scene2Snap;
    using Scene2SnapPtr  = Ref<Scene2Snap>;
    using Scene2SnapCPtr = Ref<const Scene2Snap>;
    
    struct Scene2Data;
    using Scene2DataPtr  = Ref<Scene2Data>;
    using Scene2DataCPtr = Ref<const Scene2Data>;

    template <class> class ID;
    using Scene2ID = ID<Scene2>;
    class Scene2Info;
}
