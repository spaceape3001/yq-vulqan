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
    class Spatial²;
    using Spatial²Ptr      = Ref<Spatial²>;
    using Spatial²CPtr     = Ref<const Spatial²>;

    struct Spatial²Snap;
    using Spatial²SnapPtr  = Ref<Spatial²Snap>;
    using Spatial²SnapCPtr = Ref<const Spatial²Snap>;
    
    struct Spatial²Data;
    using Spatial²DataPtr  = Ref<Spatial²Data>;
    using Spatial²DataCPtr = Ref<const Spatial²Data>;

    template <class> class ID;
    using Spatial²ID = ID<Spatial²>;
}
