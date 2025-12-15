////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PInnerTessellation2.hpp"
#include <yq/tachyon/command/tessellation/SetInnerTessellation2Command.hpp>

namespace yq::tachyon {
    PInnerTessellation²::PInnerTessellation²(const IInnerTessellation²& i) : m_innerTessellation(i.inner_tessellation())
    {
        if(i.inner_tessellation(DISABLED))
            m_flags |= F::Disabled;
        if(i.inner_tessellation(SETTABLE))
            m_flags |= F::Settable;
    }

    bool        PInnerTessellation²::inner_tessellation(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PInnerTessellation²::inner_tessellation(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    void        PInnerTessellation²::inner_tessellation(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetInnerTessellation²Command({.target=object()}, v));
        }
    }
}

