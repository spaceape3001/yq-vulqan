////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <yt/keywords.hpp>
#include <yt/typedef/accessor.hpp>
#include <cassert>

namespace yq::tachyon {

    //! Basically a data model (meant for SIMPLE typeinfo things)
    class Accessor {
    public:
        virtual Any             get(any_k) const = 0;
        virtual bool            editable() const { return false; }
        virtual void            set(const Any&) {}
        virtual ~Accessor(){}
    };

    //! Basically a data model
    template <typename T>
    class TypedAccessor : public Accessor {
    public:
        
        using Accessor::get;
        using Accessor::set;
    
        virtual T           get(value_k) const = 0;
        virtual void        set(value_k, const T&) {}
        virtual ~TypedAccessor(){}
    };
}
