////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <cstdint>
#include <tuple>
#include <string>
#include <string_view>
#include <variant>
#include <yt/keywords.hpp>
#include <yt/msg/MG.hpp>

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
    
    struct TachyonContext;

    using name_spec     = std::variant<std::monostate, const char*, std::string_view, std::string>;
    using PostTarget    = std::variant<std::monostate, MG, MGF, TachyonID, target_k>;

}
