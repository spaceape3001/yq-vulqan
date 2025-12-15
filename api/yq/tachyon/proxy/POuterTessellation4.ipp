////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "POuterTessellation4.hpp"
#include <yq/tachyon/command/tessellation/SetOuterTessellation4Command.hpp>

namespace yq::tachyon {
    POuterTessellation⁴::POuterTessellation⁴(const IOuterTessellation⁴& i) : m_outerTessellation(i.outer_tessellation())
    {
        if(i.outer_tessellation(DISABLED))
            m_flags |= F::Disabled;
        if(i.outer_tessellation(SETTABLE))
            m_flags |= F::Settable;
    }

    bool        POuterTessellation⁴::outer_tessellation(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        POuterTessellation⁴::outer_tessellation(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    void        POuterTessellation⁴::outer_tessellation(set_k, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetOuterTessellation⁴Command({.target=object()}, v));
        }
    }
}
