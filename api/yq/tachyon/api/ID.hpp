////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <compare>
#include <concepts>
#include <cstdint>

namespace yq::tachyon {
    template <class T>
    struct ID {
        uint64_t    id  = 0ULL;
        constexpr auto operator<=>(const ID&) const noexcept = default;
        constexpr operator uint64_t() const noexcept { return id; }
        
        template <class U>
        constexpr bool operator==(const ID<U>&rhs) const noexcept
        {
            return id == rhs.id;
        }
        
        template <class T2>
        requires std::derived_from<T,T2>
        constexpr operator ID<T2>() const noexcept { return { id }; }
        
        template <class T2>
        requires (!std::derived_from<T,T2>)
        explicit constexpr operator ID<T2>() const noexcept { return { id }; }
    };
    
    template <typename T>
    ID<T>   construct_id(uint64_t i) 
    {
        return { i };
    }
    
}
