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
    class Mini;
    using MiniPtr      = Ref<Mini>;
    using MiniCPtr     = Ref<const Mini>;

    template <class E>
    concept SomeMini = std::derived_from<E,Mini>;
}
