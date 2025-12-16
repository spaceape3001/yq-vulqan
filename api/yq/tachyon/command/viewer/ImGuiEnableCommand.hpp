////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiEnableCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiEnableCommand, ViewerCommand)
    public:
    
        ImGuiEnableCommand(const Header&);
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiEnableCommand(const ImGuiEnableCommand&, const Header&);
        virtual ~ImGuiEnableCommand();

    private:
        ImGuiEnableCommand(const ImGuiEnableCommand&) = delete;
        ImGuiEnableCommand(ImGuiEnableCommand&&) = delete;
        ImGuiEnableCommand& operator=(const ImGuiEnableCommand&) = delete;
        ImGuiEnableCommand& operator=(ImGuiEnableCommand&&) = delete;
    };
}
