////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeX.hpp"
#include <yq/tachyon/command/range/SetRangeXCommand.hpp>

namespace yq::tachyon {
    PRangeˣ::PRangeˣ(const IRangeˣ& i) : m_xRange(i.x_range())
    {
        if(i.x_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.x_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeˣ::~PRangeˣ()
    {
    }

    bool        PRangeˣ::x_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeˣ::x_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeˣ::x_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeˣCommand({.target=object()}, v));
        }
    }
}
