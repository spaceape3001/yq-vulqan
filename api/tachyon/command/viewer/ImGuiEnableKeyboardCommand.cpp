////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/viewer/ImGuiEnableKeyboardCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiEnableKeyboardCommand)

namespace yq::tachyon {

    ImGuiEnableKeyboardCommand::ImGuiEnableKeyboardCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiEnableKeyboardCommand::ImGuiEnableKeyboardCommand(const ImGuiEnableKeyboardCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiEnableKeyboardCommand::~ImGuiEnableKeyboardCommand()
    {
    }
        
    PostCPtr    ImGuiEnableKeyboardCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiEnableKeyboardCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiEnableKeyboardCommand::init_info()
    {
        auto w = writer<ImGuiEnableKeyboardCommand>();
        w.description("Viewer Enable ImGui Keyboard Control Command");
    }
}
