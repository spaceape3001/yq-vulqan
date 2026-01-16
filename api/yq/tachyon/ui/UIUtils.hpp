////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/Cardinal.hpp>
#include <yq/tachyon/typedef/uimisc.hpp>
#include <yq/tachyon/enum/UIFlags.hpp>
#include <yq/typedef/vector2.hpp>

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

    Vector2F    pivot_for(Cardinal v);
}
