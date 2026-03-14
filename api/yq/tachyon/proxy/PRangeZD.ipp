////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeZD.hpp"
#include <yq/tachyon/command/range/SetRangeZDCommand.hpp>

namespace yq::tachyon {
    PRangeᶻD::PRangeᶻD(const IRangeᶻD& i) : m_zRange(i.z_range())
    {
        if(i.z_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.z_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeᶻD::~PRangeᶻD()
    {
    }

    bool        PRangeᶻD::z_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeᶻD::z_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeᶻD::z_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeᶻDCommand({.target=object()}, v));
        }
    }
}
