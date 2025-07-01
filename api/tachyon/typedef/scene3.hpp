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
    class Scene³;
    using Scene³Ptr      = Ref<Scene³>;
    using Scene³CPtr     = Ref<const Scene³>;

    struct Scene³Snap;
    using Scene³SnapPtr  = Ref<Scene³Snap>;
    using Scene³SnapCPtr = Ref<const Scene³Snap>;
    
    struct Scene³Data;
    using Scene³DataPtr  = Ref<Scene³Data>;
    using Scene³DataCPtr = Ref<const Scene³Data>;

    template <class> class ID;
    using Scene³ID = ID<Scene³>;
    class Scene³Meta;
}
