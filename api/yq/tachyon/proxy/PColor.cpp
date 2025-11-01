////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PColor.hpp"
#include <yq/tachyon/command/color/SetColorCommand.hpp>

namespace yq::tachyon {
    PColor::PColor(const IColor& i) : m_color(i.color())
    {
        if(i.color(DISABLED))
            m_flags |= F::Disabled;
        if(i.color(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PColor::~PColor()
    {
    }

    RGBA4F  PColor::color() const
    {
        return m_color;
    }

    bool    PColor::color(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PColor::color(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PColor::color(set_k, const RGBA4F& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetColorCommand({.target=object()}, v));
        }
    }
}
