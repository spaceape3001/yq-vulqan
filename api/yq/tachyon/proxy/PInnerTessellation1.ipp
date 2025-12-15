////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PInnerTessellation1.hpp"
#include <yq/tachyon/command/tessellation/SetInnerTessellation1Command.hpp>

namespace yq::tachyon {
    PInnerTessellation¹::PInnerTessellation¹(const IInnerTessellation¹& i) : m_innerTessellation(i.inner_tessellation())
    {
        if(i.inner_tessellation(DISABLED))
            m_flags |= F::Disabled;
        if(i.inner_tessellation(SETTABLE))
            m_flags |= F::Settable;
    }

    bool        PInnerTessellation¹::inner_tessellation(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PInnerTessellation¹::inner_tessellation(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    void        PInnerTessellation¹::inner_tessellation(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetInnerTessellation¹Command({.target=object()}, v));
        }
    }
}
