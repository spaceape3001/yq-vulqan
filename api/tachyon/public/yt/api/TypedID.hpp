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
        
        constexpr auto operator<=>(const TypedID&b) const noexcept { return id <=> b.id; }
        constexpr operator TachyonID() const noexcept { return { id }; }
        constexpr operator uint64_t() const noexcept { return id; }
        
        constexpr bool operator()(Type t) const { return types(t); }
        
        template <typename T>
        bool    operator==(ID<T> _id) const
        {
            return _id.id == id;
        } 
        
        template <typename T>
        friend bool operator==(ID<T> _id, const TypedID& t)
        {
            return _id.id == t.id;
        }
        
        
        /*
        template <SomeTachyon T>
        constexpr operator ID<T>() const noexcept 
        {
            static const Types  _types  = meta<T>().types();
            if(types & _types == _types){
                return { id };
            } else {
                return {};
            }
        }
        */
    };
}

