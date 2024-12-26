////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition1D.hpp"
#include <yq/tachyon/commands/AdjustPosition1D.hpp>
#include <yq/tachyon/commands/SetPosition1D.hpp>

namespace yq::tachyon {
    PPosition1D::PPosition1D(const IPosition1D& i)
    {
        if(i.position1d(DISABLED))
            m_flags |= F::Disabled;
        if(i.position1d(SETTABLE))
            m_flags |= F::Settable;
        if(i.position1d(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PPosition1D::position1d(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition1D::position1d(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition1D::position1d(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PPosition1D::position1d(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition1D(id(), v));
        }
    }
    
    void        PPosition1D::position1d(adjust_t, const Vector1D& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new AdjustPosition1D(id(), v));
        }
    }
}
