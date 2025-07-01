////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/viewer/ImGuiDisableKeyboardCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiDisableKeyboardCommand)

namespace yq::tachyon {

    ImGuiDisableKeyboardCommand::ImGuiDisableKeyboardCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiDisableKeyboardCommand::ImGuiDisableKeyboardCommand(const ImGuiDisableKeyboardCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiDisableKeyboardCommand::~ImGuiDisableKeyboardCommand()
    {
    }
        
    PostCPtr    ImGuiDisableKeyboardCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiDisableKeyboardCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiDisableKeyboardCommand::init_info()
    {
        auto w = writer<ImGuiDisableKeyboardCommand>();
        w.description("Viewer Disable ImGui Keyboard Control Command");
    }
}
