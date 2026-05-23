////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Enumeration.hpp>
#include <yq/tachyon/im/combo.hpp>

namespace yq::tachyon::im {
    bool    combo(const char*, int&, const yq::EnumDef&, const combo_options_t& opts={});
    bool    combo(const char*, int&, const yq::EnumerationInfo&, const combo_options_t& opts={});

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
    
    
    template <typename E>
    requires std::is_enum_v<E>
    bool    combo(const char* label, E& e, const combo_options_t& opts = {})
    {
        int ev = (int) e;
        if(combo(label, ev, Enumeration<E>::info(), opts); (e != (E) ev)){
            e   = (E) ev;
            return true;
        }
        return false;
    }

    // todo... (RADIO)

}
