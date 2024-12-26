////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition3M.hpp"
#include <yq/tachyon/commands/AdjustPosition3M.hpp>
#include <yq/tachyon/commands/SetPosition3M.hpp>

namespace yq::tachyon {
    PPosition3M::PPosition3M(const IPosition3M& i)
    {
        if(i.position3m(DISABLED))
            m_flags |= F::Disabled;
        if(i.position3m(SETTABLE))
            m_flags |= F::Settable;
        if(i.position3m(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition3M::position3m(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition3M::position3m(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition3M::position3m(adjustable_k) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition3M::position3m(set_k, const Vector3M& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition3M(id(), v));
        }
    }
    
    void        PPosition3M::position3m(adjust_k, const Vector3M& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition3M(id(), v));
        }
    }
}
