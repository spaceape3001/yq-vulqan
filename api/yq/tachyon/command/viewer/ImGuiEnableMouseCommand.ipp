////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImGuiEnableMouseCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiEnableMouseCommand)

namespace yq::tachyon {

    ImGuiEnableMouseCommand::ImGuiEnableMouseCommand(const Header&h) : ViewerCommand(h)
    {
    }
    
    ImGuiEnableMouseCommand::ImGuiEnableMouseCommand(const ImGuiEnableMouseCommand& cp, const Header&h) : ViewerCommand(cp, h)
    {
    }

    ImGuiEnableMouseCommand::~ImGuiEnableMouseCommand()
    {
    }
        
    PostCPtr    ImGuiEnableMouseCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImGuiEnableMouseCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ImGuiEnableMouseCommand::init_meta()
    {
        auto w = writer<ImGuiEnableMouseCommand>();
        w.description("Viewer Enable ImGui Mouse Control Command");
    }
}
