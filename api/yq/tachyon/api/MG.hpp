////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq::tachyon {

    //! Mail Groups
    enum class MG : uint8_t {
        General = 0,
        Forward,
        Parent,
        Children,
        // used by objects to mail their thread
        Thread,
        // used by threads to mail their objects
        Tachyon
    };
    
    using MGF = Flags<MG>;
}
