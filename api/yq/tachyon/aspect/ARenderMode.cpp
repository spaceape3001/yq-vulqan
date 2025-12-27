////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARenderMode.hpp"
#include "ARenderModeWriter.hxx"
#include <yq/tachyon/command/widget/SetRenderModeCommand.hpp>

namespace yq::tachyon {
    ARenderMode::ARenderMode(const Param&p) : m_renderMode(p.render_mode)
    {
    }
    
    ARenderMode::ARenderMode(RenderMode dm) : m_renderMode(dm)
    {
    }
    
    ARenderMode::~ARenderMode() = default;

    void    ARenderMode::render_mode(set_k, RenderMode v)
    {
        m_renderMode = v;       
        mark();
    }

    void    ARenderMode::on_set_render_mode(const SetRenderModeCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        render_mode(SET, cmd.render_mode());
    }
}

