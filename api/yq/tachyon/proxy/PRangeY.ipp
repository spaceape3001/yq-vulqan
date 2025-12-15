////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeY.hpp"
#include <yq/tachyon/command/range/SetRangeYCommand.hpp>

namespace yq::tachyon {
    PRangeʸ::PRangeʸ(const IRangeʸ& i) : m_yRange(i.y_range())
    {
        if(i.y_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.y_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeʸ::~PRangeʸ()
    {
    }

    bool        PRangeʸ::y_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeʸ::y_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeʸ::y_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeʸCommand({.target=object()}, v));
        }
    }
}
