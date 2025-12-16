////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiDisableKeyboardCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiDisableKeyboardCommand, ViewerCommand)
    public:
    
        ImGuiDisableKeyboardCommand(const Header&);
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiDisableKeyboardCommand(const ImGuiDisableKeyboardCommand&, const Header&);
        virtual ~ImGuiDisableKeyboardCommand();

    private:
        ImGuiDisableKeyboardCommand(const ImGuiDisableKeyboardCommand&) = delete;
        ImGuiDisableKeyboardCommand(ImGuiDisableKeyboardCommand&&) = delete;
        ImGuiDisableKeyboardCommand& operator=(const ImGuiDisableKeyboardCommand&) = delete;
        ImGuiDisableKeyboardCommand& operator=(ImGuiDisableKeyboardCommand&&) = delete;
    };
}
