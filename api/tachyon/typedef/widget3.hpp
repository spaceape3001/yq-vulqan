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
    class Widget³;
    using Widget³Ptr      = Ref<Widget³>;
    using Widget³CPtr     = Ref<const Widget³>;

    struct Widget³Snap;
    using Widget³SnapPtr  = Ref<Widget³Snap>;
    using Widget³SnapCPtr = Ref<const Widget³Snap>;
    
    struct Widget³Data;
    using Widget³DataPtr  = Ref<Widget³Data>;
    using Widget³DataCPtr = Ref<const Widget³Data>;

    template <class E>
    concept SomeWidget³ = std::derived_from<E,Widget³>;

    template <class> class ID;
    using Widget³ID = ID<Widget³>;
}
