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
    class Rendered3;
    using Rendered3Ptr       = Ref<Rendered3>;
    using Rendered3CPtr      = Ref<const Rendered3>;

    struct Rendered3Snap;
    using Rendered3SnapPtr  = Ref<Rendered3Snap>;
    using Rendered3SnapCPtr = Ref<const Rendered3Snap>;
    
    struct Rendered3Data;
    using Rendered3DataPtr  = Ref<Rendered3Data>;
    using Rendered3DataCPtr = Ref<const Rendered3Data>;

    template <class> class ID;
    
    using Rendered3ID = ID<Rendered3>;
}
