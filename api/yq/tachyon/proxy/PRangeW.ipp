////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeW.hpp"
#include <yq/tachyon/command/range/SetRangeWCommand.hpp>

namespace yq::tachyon {
    PRangeʷ::PRangeʷ(const IRangeʷ& i) : m_wRange(i.w_range())
    {
        if(i.w_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.w_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeʷ::~PRangeʷ()
    {
    }

    bool        PRangeʷ::w_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeʷ::w_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeʷ::w_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeʷCommand({.target=object()}, v));
        }
    }
}
