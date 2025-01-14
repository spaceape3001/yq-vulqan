////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Type.hpp>
#include <yt/api/ID.hpp>
#include <yt/typedef/tachyon.hpp>
#include <compare>
#include <cstdint>

namespace yq::tachyon {
    class Tachyon;

    struct TypedID {
        uint64_t    id      = 0ULL;
        Types       types   = {};
        
        constexpr TypedID() noexcept {}
        TypedID(const Tachyon&);
        TypedID(const Tachyon*);
        
        constexpr TypedID(uint64_t _id, Types _types) noexcept : id(_id), types(_types) {}
        
        constexpr auto operator<=>(const TypedID&b) const noexcept { return id <=> b.id; }
        constexpr operator TachyonID() const noexcept { return { id }; }
        constexpr operator uint64_t() const noexcept { return id; }
        
        constexpr bool operator()(Type t) const { return types(t); }
        
        constexpr auto    operator<=>(TypedID rhs) const
        {
            return id <=> rhs.id;
        } 

        template <typename T>
        auto    operator<=>(ID<T> _id) const
        {
            return id <=> _id.id;
        } 
        
        template <typename T>
        friend auto operator<=>(ID<T> _id, const TypedID& t)
        {
            return _id.id <=> t.id;
        }
        
        constexpr TachyonID   tachyonID() const noexcept
        {
            return { id };
        }
        
        template <SomeTachyon T>
        constexpr ID<T> as() const noexcept 
        {
            static const Types  _types  = meta<T>().types();
            if((types & _types) == _types){
                return { id };
            } else {
                return {};
            }
        }
    };
}

