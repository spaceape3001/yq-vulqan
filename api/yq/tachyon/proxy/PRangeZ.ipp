////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeZ.hpp"
#include <yq/tachyon/command/range/SetRangeZCommand.hpp>

namespace yq::tachyon {
    PRangeᶻ::PRangeᶻ(const IRangeᶻ& i) : m_zRange(i.z_range())
    {
        if(i.z_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.z_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeᶻ::~PRangeᶻ()
    {
    }

    bool        PRangeᶻ::z_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeᶻ::z_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeᶻ::z_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeᶻCommand({.target=object()}, v));
        }
    }
}
