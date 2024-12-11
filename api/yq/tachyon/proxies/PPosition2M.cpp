////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2M.hpp"
#include <yq/tachyon/commands/AdjustPosition2M.hpp>
#include <yq/tachyon/commands/SetPosition2M.hpp>

namespace yq::tachyon {
    PPosition2M::PPosition2M(const IPosition2M& i)
    {
        if(i.position2m(DISABLED))
            m_flags |= F::Disabled;
        if(i.position2m(SETTABLE))
            m_flags |= F::Settable;
        if(i.position2m(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition2M::position2m(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition2M::position2m(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition2M::position2m(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition2M::position2m(set_t, const Vector2M& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition2M(id(), v));
        }
    }
    
    void        PPosition2M::position2m(adjust_t, const Vector2M& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition2M(id(), v));
        }
    }
}
