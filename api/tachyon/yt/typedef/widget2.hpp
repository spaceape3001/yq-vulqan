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
    class Widget²;
    using Widget²Ptr      = Ref<Widget²>;
    using Widget²CPtr     = Ref<const Widget²>;

    struct Widget²Snap;
    using Widget²SnapPtr  = Ref<Widget²Snap>;
    using Widget²SnapCPtr = Ref<const Widget²Snap>;
    
    struct Widget²Data;
    using Widget²DataPtr  = Ref<Widget²Data>;
    using Widget²DataCPtr = Ref<const Widget²Data>;

    template <class E>
    concept SomeWidget² = std::derived_from<E,Widget²>;

    template <class> class ID;
    using Widget²ID = ID<Widget²>;
}
