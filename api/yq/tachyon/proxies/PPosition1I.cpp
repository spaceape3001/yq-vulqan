////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1I.hpp"
#include <yq/tachyon/commands/AdjustPosition1I.hpp>
#include <yq/tachyon/commands/SetPosition1I.hpp>

namespace yq::tachyon {
    PPosition1I::PPosition1I(const IPosition1I& i)
    {
        if(i.position1i(DISABLED))
            m_flags |= F::Disabled;
        if(i.position1i(SETTABLE))
            m_flags |= F::Settable;
        if(i.position1i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition1I::position1i(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition1I::position1i(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition1I::position1i(adjustable_k) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition1I::position1i(set_k, const Vector1I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition1I(id(), v));
        }
    }
    
    void        PPosition1I::position1i(adjust_k, const Vector1I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition1I(id(), v));
        }
    }
}
