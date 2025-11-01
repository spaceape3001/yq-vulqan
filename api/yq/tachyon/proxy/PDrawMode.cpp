////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PDrawMode.hpp"
#include <tachyon/command/shape/SetDrawModeCommand.hpp>

namespace yq::tachyon {
    PDrawMode::PDrawMode(const IDrawMode& i) : m_drawMode(i.draw_mode()), m_drawModeUse(i.draw_mode(USE))
    {
        if(i.draw_mode(DISABLED))
            m_flags |= F::Disabled;
        if(i.draw_mode(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PDrawMode::~PDrawMode()
    {
    }

    DrawMode  PDrawMode::draw_mode() const
    {
        return m_drawMode;
    }

    DrawMode  PDrawMode::draw_mode(use_k) const 
    {
        return m_drawModeUse;
    }

    bool    PDrawMode::draw_mode(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PDrawMode::draw_mode(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PDrawMode::draw_mode(set_k, DrawMode v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled))
            mail(new SetDrawModeCommand({.target=object()}, v));
    }
}
