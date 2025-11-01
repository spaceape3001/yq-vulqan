////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ViewerCommand.hpp>
#include <tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiDisableKeyboardCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiDisableKeyboardCommand, ViewerCommand)
    public:
    
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
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
