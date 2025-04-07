////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/uimisc.hpp>

namespace yq::tachyon {
    constexpr bool    undefined(horzvert_t hv)
    {
        return static_cast<bool>(std::get_if<std::monostate>(&hv));
    }
    
    constexpr bool    horizontal(horzvert_t hv)
    {
        return static_cast<bool>(std::get_if<horizontal_k>(&hv));
    }
    
    constexpr bool    vertical(horzvert_t hv)
    {
        return static_cast<bool>(std::get_if<vertical_k>(&hv));
    }
}
