////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/tachyon/im/combo.hpp>

namespace yq::tachyon::im {
    bool    combo(const char*, int&, const yq::EnumDef&, const combo_options_t& opts={});

    template <typename E>
    bool    combo(const char* label, yq::EnumImpl<E>& e, const combo_options_t& opts={})
    {
        int v   = e.value();
        bool f = combo(label, v, *E::staticEnumInfo(), opts);
        if(f && v != e.value()){
            e   = (typename E::enum_t) v;
            return true;
        } else
            return false;
    }

    // todo... (RADIO)

}
