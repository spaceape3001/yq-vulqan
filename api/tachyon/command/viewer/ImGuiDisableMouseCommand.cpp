////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/viewer/ImGuiDisableMouseCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiDisableMouseCommand)

namespace yq::tachyon {

    ImGuiDisableMouseCommand::ImGuiDisableMouseCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiDisableMouseCommand::ImGuiDisableMouseCommand(const ImGuiDisableMouseCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiDisableMouseCommand::~ImGuiDisableMouseCommand()
    {
    }
        
    PostCPtr    ImGuiDisableMouseCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiDisableMouseCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiDisableMouseCommand::init_info()
    {
        auto w = writer<ImGuiDisableMouseCommand>();
        w.description("Viewer Disable ImGui Mouse Control Command");
    }
}
