////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>

namespace yq { 
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Delegate;
    class DelegateInfo;
    using DelegatePtr           = Ref<Delegate>;
    using DelegateCPtr          = Ref<const Delegate>;

    template <class C>
    concept SomeDelegate        = std::derived_from<C,Delegate>;
}
