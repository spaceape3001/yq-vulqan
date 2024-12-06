////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4D.hpp"
#include <yq/tachyon/commands/AdjustPosition4D.hpp>
#include <yq/tachyon/commands/SetPosition4D.hpp>

namespace yq::tachyon {
    PPosition4D::PPosition4D(const IPosition4D& i)
    {
        if(i.position4d(DISABLED))
            m_flags |= F::Disabled;
        if(i.position4d(SETTABLE))
            m_flags |= F::Settable;
        if(i.position4d(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition4D::position4d(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition4D::position4d(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition4D::position4d(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition4D::position4d(set_t, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition4D(id(), v));
        }
    }
    
    void        PPosition4D::position4d(adjust_t, const Vector4D& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition4D(id(), v));
        }
    }
}
