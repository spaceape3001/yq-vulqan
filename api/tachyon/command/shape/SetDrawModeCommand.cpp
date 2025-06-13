////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/shape/SetDrawModeCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetDrawModeCommand)

namespace yq::tachyon {

    SetDrawModeCommand::SetDrawModeCommand(const Header&h, DrawMode dm) : ShapeCommand(h), m_drawMode(dm)
    {
    }

    SetDrawModeCommand::SetDrawModeCommand(const SetDrawModeCommand& cp, const Header& h) : 
        ShapeCommand(cp, h), m_drawMode(cp.m_drawMode)
    {
    }
    
    SetDrawModeCommand::~SetDrawModeCommand()
    {
    }

    PostCPtr    SetDrawModeCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetDrawModeCommand(*this, h);
    }
    
    void        SetDrawModeCommand::set_draw_mode(DrawMode v)
    {
        m_drawMode  = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetDrawModeCommand::init_info()
    {
        auto w = writer<SetDrawModeCommand>();
        w.description("SetDrawMode Command");
        w.property("draw_mode", &SetDrawModeCommand::m_drawMode).tag({kTag_Log, kTag_Save});
    }
}
