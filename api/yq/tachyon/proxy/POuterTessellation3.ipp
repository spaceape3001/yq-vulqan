////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "POuterTessellation3.hpp"
#include <yq/tachyon/command/tessellation/SetOuterTessellation3Command.hpp>

namespace yq::tachyon {
    POuterTessellation³::POuterTessellation³(const IOuterTessellation³& i) : m_outerTessellation(i.outer_tessellation())
    {
        if(i.outer_tessellation(DISABLED))
            m_flags |= F::Disabled;
        if(i.outer_tessellation(SETTABLE))
            m_flags |= F::Settable;
    }

    bool        POuterTessellation³::outer_tessellation(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        POuterTessellation³::outer_tessellation(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    void        POuterTessellation³::outer_tessellation(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOuterTessellation³Command({.target=object()}, v));
        }
    }
}
