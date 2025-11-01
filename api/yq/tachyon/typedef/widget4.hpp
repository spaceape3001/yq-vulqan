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
    class Widget⁴;
    using Widget⁴Ptr      = Ref<Widget⁴>;
    using Widget⁴CPtr     = Ref<const Widget⁴>;

    struct Widget⁴Snap;
    using Widget⁴SnapPtr  = Ref<Widget⁴Snap>;
    using Widget⁴SnapCPtr = Ref<const Widget⁴Snap>;
    
    struct Widget⁴Data;
    using Widget⁴DataPtr  = Ref<Widget⁴Data>;
    using Widget⁴DataCPtr = Ref<const Widget⁴Data>;

    template <class E>
    concept SomeWidget⁴ = std::derived_from<E,Widget⁴>;

    template <class> class ID;
    using Widget⁴ID = ID<Widget⁴>;
}
