////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2D.hpp"
#include <yq/tachyon/commands/AdjustPosition2D.hpp>
#include <yq/tachyon/commands/SetPosition2D.hpp>

namespace yq::tachyon {
    PPosition2D::PPosition2D(const IPosition2D& i)
    {
        if(i.position2d(DISABLED))
            m_flags |= F::Disabled;
        if(i.position2d(SETTABLE))
            m_flags |= F::Settable;
        if(i.position2d(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition2D::position2d(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition2D::position2d(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition2D::position2d(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition2D::position2d(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition2D(id(), v));
        }
    }
    
    void        PPosition2D::position2d(adjust_k, const Vector2D& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition2D(id(), v));
        }
    }
}
