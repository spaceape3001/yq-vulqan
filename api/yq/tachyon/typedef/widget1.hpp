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
    class Widget¹;
    using Widget¹Ptr      = Ref<Widget¹>;
    using Widget¹CPtr     = Ref<const Widget¹>;

    struct Widget¹Snap;
    using Widget¹SnapPtr  = Ref<Widget¹Snap>;
    using Widget¹SnapCPtr = Ref<const Widget¹Snap>;
    
    struct Widget¹Data;
    using Widget¹DataPtr  = Ref<Widget¹Data>;
    using Widget¹DataCPtr = Ref<const Widget¹Data>;

    template <class E>
    concept SomeWidget¹ = std::derived_from<E,Widget¹>;

    template <class> class ID;
    using Widget¹ID = ID<Widget¹>;
}
