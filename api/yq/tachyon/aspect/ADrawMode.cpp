////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ADrawMode.hpp"
#include "ADrawModeWriter.hxx"
#include <yq/tachyon/command/shape/SetDrawModeCommand.hpp>

namespace yq::tachyon {
    ADrawMode::ADrawMode(const Param&p) : m_drawMode(p.draw_mode)
    {
    }
    
    ADrawMode::ADrawMode(DrawMode dm) : m_drawMode(dm)
    {
    }
    
    ADrawMode::~ADrawMode() = default;

    void    ADrawMode::draw_mode(set_k, DrawMode v)
    {
        m_drawMode = v;       
        mark();
    }

    void    ADrawMode::on_set_draw_mode(const SetDrawModeCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        draw_mode(SET, cmd.draw_mode());
    }
}

