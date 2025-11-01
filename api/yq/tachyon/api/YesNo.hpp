////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <variant>

namespace yq::tachyon {
    using YesNo     = std::variant<bool, yes_k, no_k, accept_k, reject_k>;
    
    constexpr bool is_accept(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return *p;
        return std::get_if<yes_k>(&yn) || std::get_if<accept_k>(&yn);
    }

    constexpr bool is_no(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return !*p;
        return std::get_if<no_k>(&yn) || std::get_if<reject_k>(&yn);
    }

    constexpr bool is_reject(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return !*p;
        return std::get_if<no_k>(&yn) || std::get_if<reject_k>(&yn);
    }

    constexpr bool is_yes(YesNo yn)
    {
        if(auto p = std::get_if<bool>(&yn))
            return *p;
        return std::get_if<yes_k>(&yn) || std::get_if<accept_k>(&yn);
    }

}
