////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PBgColor.hpp"
#include <yq/tachyon/command/color/SetBgColorCommand.hpp>

namespace yq::tachyon {
    PBgColor::PBgColor(const IBgColor& i) : m_bgcolor(i.bgcolor())
    {
        if(i.bgcolor(DISABLED))
            m_flags |= F::Disabled;
        if(i.bgcolor(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PBgColor::~PBgColor()
    {
    }

    RGBA4F  PBgColor::bgcolor() const
    {
        return m_bgcolor;
    }

    bool    PBgColor::bgcolor(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PBgColor::bgcolor(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PBgColor::bgcolor(set_k, const RGBA4F& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetBgColorCommand({.target=object()}, v));
        }
    }
}
