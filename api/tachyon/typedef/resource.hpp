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
    class Resource;
    class ResourceInfo;
    using ResourcePtr           = Ref<Resource>;
    using ResourceCPtr          = Ref<const Resource>;

    template <class C>
    concept SomeResource        = std::derived_from<C,Resource>;
}
