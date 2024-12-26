////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1M.hpp"
#include <yq/tachyon/commands/AdjustPosition1M.hpp>
#include <yq/tachyon/commands/SetPosition1M.hpp>

namespace yq::tachyon {
    PPosition1M::PPosition1M(const IPosition1M& i)
    {
        if(i.position1m(DISABLED))
            m_flags |= F::Disabled;
        if(i.position1m(SETTABLE))
            m_flags |= F::Settable;
        if(i.position1m(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition1M::position1m(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition1M::position1m(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition1M::position1m(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition1M::position1m(set_k, const Vector1M& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition1M(id(), v));
        }
    }
    
    void        PPosition1M::position1m(adjust_k, const Vector1M& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition1M(id(), v));
        }
    }
}
