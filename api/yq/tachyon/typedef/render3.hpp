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
    class Render3;
    using Render3Ptr       = Ref<Render3>;
    using Render3CPtr      = Ref<const Render3>;

    struct Render3Snap;
    using Render3SnapPtr  = Ref<Render3Snap>;
    using Render3SnapCPtr = Ref<const Render3Snap>;
    
    struct Render³Data;
    using Render³DataPtr  = Ref<Render³Data>;
    using Render³DataCPtr = Ref<const Render³Data>;

    template <class> class ID;
    
    using Render3ID = ID<Render3>;
}
