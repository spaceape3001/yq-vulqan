////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <variant>

namespace yq::tachyon {
    using YesNo     = std::variant<bool, yes_t, no_t, accept_t, reject_t>;
    
    constexpr bool is_accept(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return *p;
        return std::get_if<yes_t>(&yn) || std::get_if<accept_t>(&yn);
    }

    constexpr bool is_no(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return !*p;
        return std::get_if<no_t>(&yn) || std::get_if<reject_t>(&yn);
    }

    constexpr bool is_reject(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return !*p;
        return std::get_if<no_t>(&yn) || std::get_if<reject_t>(&yn);
    }

    constexpr bool is_yes(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return *p;
        return std::get_if<yes_t>(&yn) || std::get_if<accept_t>(&yn);
    }

}
