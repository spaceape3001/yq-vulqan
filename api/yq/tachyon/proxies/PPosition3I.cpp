////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3I.hpp"
#include <yq/tachyon/commands/AdjustPosition3I.hpp>
#include <yq/tachyon/commands/SetPosition3I.hpp>

namespace yq::tachyon {
    PPosition3I::PPosition3I(const IPosition3I& i)
    {
        if(i.position3i(DISABLED))
            m_flags |= F::Disabled;
        if(i.position3i(SETTABLE))
            m_flags |= F::Settable;
        if(i.position3i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition3I::position3i(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition3I::position3i(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition3I::position3i(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition3I::position3i(set_k, const Vector3I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition3I(id(), v));
        }
    }
    
    void        PPosition3I::position3i(adjust_t, const Vector3I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition3I(id(), v));
        }
    }
}
