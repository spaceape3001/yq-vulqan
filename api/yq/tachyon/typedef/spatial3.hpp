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
    class Spatial³;
    using Spatial³Ptr      = Ref<Spatial³>;
    using Spatial³CPtr     = Ref<const Spatial³>;

    struct Spatial³Snap;
    using Spatial³SnapPtr  = Ref<Spatial³Snap>;
    using Spatial³SnapCPtr = Ref<const Spatial³Snap>;
    
    struct Spatial³Data;
    using Spatial³DataPtr  = Ref<Spatial³Data>;
    using Spatial³DataCPtr = Ref<const Spatial³Data>;

    template <class> class ID;
    using Spatial³ID = ID<Spatial³>;

    class Spatial³Meta;
}
