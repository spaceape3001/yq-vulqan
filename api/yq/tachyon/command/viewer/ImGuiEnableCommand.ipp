////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImGuiEnableCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiEnableCommand)

namespace yq::tachyon {

    ImGuiEnableCommand::ImGuiEnableCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiEnableCommand::ImGuiEnableCommand(const ImGuiEnableCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiEnableCommand::~ImGuiEnableCommand()
    {
    }
        
    PostCPtr    ImGuiEnableCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiEnableCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiEnableCommand::init_meta()
    {
        auto w = writer<ImGuiEnableCommand>();
        w.description("Viewer Enable ImGui  Control Command");
    }
}
