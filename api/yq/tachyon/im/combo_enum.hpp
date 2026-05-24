////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enumeration.hpp>
#include <yq/tachyon/im/combo.hpp>

namespace yq::tachyon::im {
    bool    combo(const char*, int&, const yq::EnumerationInfo&, const combo_options_t& opts={});

    
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
