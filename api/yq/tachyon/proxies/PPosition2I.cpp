////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2I.hpp"
#include <yq/tachyon/commands/AdjustPosition2I.hpp>
#include <yq/tachyon/commands/SetPosition2I.hpp>

namespace yq::tachyon {
    PPosition2I::PPosition2I(const IPosition2I& i)
    {
        if(i.position2i(DISABLED))
            m_flags |= F::Disabled;
        if(i.position2i(SETTABLE))
            m_flags |= F::Settable;
        if(i.position2i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition2I::position2i(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition2I::position2i(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition2I::position2i(adjustable_k) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition2I::position2i(set_k, const Vector2I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition2I(id(), v));
        }
    }
    
    void        PPosition2I::position2i(adjust_k, const Vector2I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition2I(id(), v));
        }
    }
}
