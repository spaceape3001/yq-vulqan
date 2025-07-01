////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Type.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yq/meta/MetaBinder.hpp>
#include <tachyon/api/StdThread.hpp>
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
        
        TypedID(StdThread);
        
        /*! \brief Constructor
        
            \note This one strips away the types information (that's why it's explicit)
        */
        constexpr explicit TypedID(const TachyonID& i) noexcept : id(i.id), types{} {}
        
        constexpr TypedID(uint64_t _id, Types _types) noexcept : id(_id), types(_types) {}
        constexpr TypedID(const TachyonID& i, Types _types) noexcept : id(i.id), types(_types) {}
        
        constexpr auto operator<=>(const TypedID&b) const noexcept { return id <=> b.id; }
        constexpr operator TachyonID() const noexcept { return { id }; }
        constexpr operator uint64_t() const noexcept { return id; }
        
        constexpr bool operator()(Type t) const noexcept { return types(t); }
        
        template <typename T>
        auto    operator<=>(ID<T> _id) const noexcept
        {
            return id <=> _id.id;
        } 
        
        template <typename T>
        friend auto operator<=>(ID<T> _id, const TypedID& t) noexcept
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

YQ_TYPE_DECLARE(yq::tachyon::TypedID)


