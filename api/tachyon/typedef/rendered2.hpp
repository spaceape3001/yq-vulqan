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
    class Rendered²;
    using Rendered²Ptr       = Ref<Rendered²>;
    using Rendered²CPtr      = Ref<const Rendered²>;

    struct Rendered²Snap;
    using Rendered²SnapPtr  = Ref<Rendered²Snap>;
    using Rendered²SnapCPtr = Ref<const Rendered²Snap>;
    
    struct Rendered²Data;
    using Rendered²DataPtr  = Ref<Rendered²Data>;
    using Rendered²DataCPtr = Ref<const Rendered²Data>;

    template <class> class ID;
    
    using Rendered²ID = ID<Rendered²>;
}
