////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImGuiDisableCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiDisableCommand)

namespace yq::tachyon {

    ImGuiDisableCommand::ImGuiDisableCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiDisableCommand::ImGuiDisableCommand(const ImGuiDisableCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiDisableCommand::~ImGuiDisableCommand()
    {
    }
        
    PostCPtr    ImGuiDisableCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiDisableCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiDisableCommand::init_meta()
    {
        auto w = writer<ImGuiDisableCommand>();
        w.description("Viewer Disable ImGui  Control Command");
    }
}
