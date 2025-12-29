////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MyImGui.hpp>
#include <yq/core/Tristate.hpp>

namespace yq::tachyon::im {

    bool    checkbox(const char*, bool&);
    
    //! It'll cycle yes/no/maybe
    bool    checkbox(const char*, Tristate&);

}
