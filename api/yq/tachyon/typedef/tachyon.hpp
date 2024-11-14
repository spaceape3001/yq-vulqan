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
    class Tachyon;
    class TachyonInfo;
    using TachyonPtr    = Ref<Tachyon>;
    using TachyonCPtr   = Ref<const Tachyon>;

    template <class E>
    concept SomeTachyon = std::derived_from<E,Tachyon>;
}
