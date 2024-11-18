////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <cstdint>

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

    template <class> class ID;
    using TachyonID = ID<Tachyon>;
    
    struct TachyonData;
    using TachyonDataPtr    = Ref<TachyonData>;
    using TachyonDataCPtr   = Ref<const TachyonData>;

    struct TachyonSnap;
    using TachyonSnapPtr    = Ref<TachyonSnap>;
    using TachyonSnapCPtr   = Ref<const TachyonSnap>;
}
