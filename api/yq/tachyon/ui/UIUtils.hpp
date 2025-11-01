////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/uimisc.hpp>
#include <tachyon/enum/Cardinal.hpp>
#include <tachyon/enum/UIFlags.hpp>
#include <yq/typedef/vector2.hpp>

namespace yq::tachyon {
    enum class Cardinal;

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
