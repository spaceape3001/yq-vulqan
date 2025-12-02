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
    class Builder;
    using BuilderPtr           = Ref<Builder>;
    using BuilderCPtr          = Ref<const Builder>;

    template <class C>
    concept SomeBuilder        = std::derived_from<C,Builder>;
}
