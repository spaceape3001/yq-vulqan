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
    class Render³;
    using Render³Ptr       = Ref<Render³>;
    using Render³CPtr      = Ref<const Render³>;

    struct Render³Snap;
    using Render³SnapPtr  = Ref<Render³Snap>;
    using Render³SnapCPtr = Ref<const Render³Snap>;
    
    struct Render³Data;
    using Render³DataPtr  = Ref<Render³Data>;
    using Render³DataCPtr = Ref<const Render³Data>;

    template <class> class ID;
    
    using Render³ID = ID<Render³>;
}
