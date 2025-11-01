////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Accessor.hpp>

namespace yq::tachyon {
    template <typename T>
    class PointerAccessor : public Accessor<T> {
    public:
    
        typename Accessor<T>::value_t get() const 
        {
            return m_pointer;
        }
        
        bool    editable() 
        { 
            return true; 
        }
        
        void    set(const T& v)
        {
            *m_pointer  = v;
        }
    
    private:
        constexpr PointerAccessor(T* v) : m_pointer(v)
        {
            assert(v);
        }
        
        T* const    m_pointer;
    };
}
