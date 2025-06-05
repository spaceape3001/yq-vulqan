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
    class Rendered³;
    using Rendered³Ptr       = Ref<Rendered³>;
    using Rendered³CPtr      = Ref<const Rendered³>;

    struct Rendered³Snap;
    using Rendered³SnapPtr  = Ref<Rendered³Snap>;
    using Rendered³SnapCPtr = Ref<const Rendered³Snap>;
    
    struct Rendered³Data;
    using Rendered³DataPtr  = Ref<Rendered³Data>;
    using Rendered³DataCPtr = Ref<const Rendered³Data>;

    template <class> class ID;
    
    using Rendered³ID = ID<Rendered³>;
    class Rendered³Info;
}
