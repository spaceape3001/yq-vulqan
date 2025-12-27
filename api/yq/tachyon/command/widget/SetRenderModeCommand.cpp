////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/widget/SetRenderModeCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRenderModeCommand)

namespace yq::tachyon {
    SetRenderModeCommand::SetRenderModeCommand(const Header& h, RenderMode vid) : WidgetCommand(h), m_renderMode(vid)
    {
    }

    SetRenderModeCommand::SetRenderModeCommand(const SetRenderModeCommand& cp, const Header& h) : 
        WidgetCommand(cp, h), m_renderMode(cp.m_renderMode)
    {
    }

    SetRenderModeCommand::~SetRenderModeCommand()
    {
    }
    
    PostCPtr    SetRenderModeCommand::clone(rebind_k, const Header&h) const
    {
        return new SetRenderModeCommand(*this, h);
    }

    void SetRenderModeCommand::init_meta()
    {
        auto w = writer<SetRenderModeCommand>();
        w.description("Set Viewer Command");
        w.property("render_mode", &SetRenderModeCommand::m_renderMode);
    }
}
