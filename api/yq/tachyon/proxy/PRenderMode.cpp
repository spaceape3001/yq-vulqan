////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRenderMode.hpp"
#include <yq/tachyon/command/widget/SetRenderModeCommand.hpp>

namespace yq::tachyon {
    PRenderMode::PRenderMode(const IRenderMode& i) : m_renderMode(i.render_mode())
    {
        if(i.render_mode(DISABLED))
            m_flags |= F::Disabled;
        if(i.render_mode(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PRenderMode::~PRenderMode()
    {
    }

    RenderMode  PRenderMode::render_mode() const
    {
        return m_renderMode;
    }

    bool    PRenderMode::render_mode(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PRenderMode::render_mode(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PRenderMode::render_mode(set_k, RenderMode v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled))
            mail(new SetRenderModeCommand({.target=object()}, v));
    }
}
