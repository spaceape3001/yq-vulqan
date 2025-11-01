////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <cstdint>
#include <map>
#include <tuple>
#include <set>
#include <string>
#include <string_view>
#include <variant>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/MG.hpp>

namespace yq { 
    template <typename> class Ref;
    class Any;
    struct IgCase;
}

namespace yq::tachyon {
    class Tachyon;
    class TachyonMeta;
    class TypedID;
    
    using TachyonPtr    = Ref<Tachyon>;
    using TachyonCPtr   = Ref<const Tachyon>;

    using TachyonPtrVector  = std::vector<TachyonPtr>;

    template <class E>
    concept SomeTachyon = std::derived_from<E,Tachyon>;

    template <class> class ID;
    using TachyonID = ID<Tachyon>;
    
    using TachyonIDSet  = std::set<TachyonID>;
    
    struct TachyonData;
    using TachyonDataPtr    = Ref<TachyonData>;
    using TachyonDataCPtr   = Ref<const TachyonData>;

    struct TachyonSnap;
    using TachyonSnapPtr    = Ref<TachyonSnap>;
    using TachyonSnapCPtr   = Ref<const TachyonSnap>;
    
    struct TachyonContext;

    using name_spec     = std::variant<std::monostate, const char*, std::string_view, std::string>;
    using PostTarget    = std::variant<std::monostate, MG, MGF, TachyonID, StdThread, target_k>;

    using TachyonSpec  = std::variant<std::monostate, TachyonID, TypedID>;

    //! Application defined custom attributes
    using AttrIDMap         = std::map<int,Any>;
    
    //! User defined custom attributes
    using AttrKeyMap        = std::map<std::string,Any,IgCase>;
}
