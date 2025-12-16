////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiDisableCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiDisableCommand, ViewerCommand)
    public:
    
        ImGuiDisableCommand(const Header&);
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiDisableCommand(const ImGuiDisableCommand&, const Header&);
        virtual ~ImGuiDisableCommand();

    private:
        ImGuiDisableCommand(const ImGuiDisableCommand&) = delete;
        ImGuiDisableCommand(ImGuiDisableCommand&&) = delete;
        ImGuiDisableCommand& operator=(const ImGuiDisableCommand&) = delete;
        ImGuiDisableCommand& operator=(ImGuiDisableCommand&&) = delete;
    };
}
