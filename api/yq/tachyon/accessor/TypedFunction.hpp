////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>
#include <tachyon/typedef/accessors.hpp>
#include <functional>

namespace yq::tachyon {

    template <typename T>
    class TypedFunction : public TypedAccessor<T> {
    public:

        using FN = std::function<T()>;

        TypedFunction(FN&& fn) : m_function(std::move(fn))
        {
        }
        
        Any                 get(any_k) const 
        {
            return Any(m_function());
        }
        
        T                   get(value_k) const 
        {
            return m_function();
        }
        
        ~TypedFunction()
        {
        }
        
    private:
        FN                  m_function;
    };
}
