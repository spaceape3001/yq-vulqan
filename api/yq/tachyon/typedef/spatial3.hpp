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
    class Spatial3;
    using Spatial3Ptr      = Ref<Spatial3>;
    using Spatial3CPtr     = Ref<const Spatial3>;

    struct Spatial3Snap;
    using Spatial3SnapPtr  = Ref<Spatial3Snap>;
    using Spatial3SnapCPtr = Ref<const Spatial3Snap>;
    
    struct Spatial3Data;
    using Spatial3DataPtr  = Ref<Spatial3Data>;
    using Spatial3DataCPtr = Ref<const Spatial3Data>;

    template <class> class ID;
    using Spatial3ID = ID<Spatial3>;
}
