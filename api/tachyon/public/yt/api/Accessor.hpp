////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/accessor.hpp>
#include <cassert>
#include <variant>

namespace yq::tachyon {

    //! Basically a data model
    template <typename T>
    class Accessor {
    public:
        using value_t   = std::variant<std::monostate, T, T*, const T*>;
        virtual value_t     get() const = 0;
        virtual bool        editable() const { return false; }
        virtual void        set(const T&) {}
        virtual ~Accessor(){}
    };
    
    //template <typename T>
    //using AccessorValue = typename Accessor<T>::value_t;
}
