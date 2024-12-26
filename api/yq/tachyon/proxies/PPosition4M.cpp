////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4M.hpp"
#include <yq/tachyon/commands/AdjustPosition4M.hpp>
#include <yq/tachyon/commands/SetPosition4M.hpp>

namespace yq::tachyon {
    PPosition4M::PPosition4M(const IPosition4M& i)
    {
        if(i.position4m(DISABLED))
            m_flags |= F::Disabled;
        if(i.position4m(SETTABLE))
            m_flags |= F::Settable;
        if(i.position4m(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition4M::position4m(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition4M::position4m(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition4M::position4m(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition4M::position4m(set_k, const Vector4M& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition4M(id(), v));
        }
    }
    
    void        PPosition4M::position4m(adjust_k, const Vector4M& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition4M(id(), v));
        }
    }
}
