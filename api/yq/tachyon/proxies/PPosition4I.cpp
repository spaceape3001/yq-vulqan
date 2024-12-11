////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4I.hpp"
#include <yq/tachyon/commands/AdjustPosition4I.hpp>
#include <yq/tachyon/commands/SetPosition4I.hpp>

namespace yq::tachyon {
    PPosition4I::PPosition4I(const IPosition4I& i)
    {
        if(i.position4i(DISABLED))
            m_flags |= F::Disabled;
        if(i.position4i(SETTABLE))
            m_flags |= F::Settable;
        if(i.position4i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition4I::position4i(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition4I::position4i(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition4I::position4i(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition4I::position4i(set_t, const Vector4I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition4I(id(), v));
        }
    }
    
    void        PPosition4I::position4i(adjust_t, const Vector4I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition4I(id(), v));
        }
    }
}
