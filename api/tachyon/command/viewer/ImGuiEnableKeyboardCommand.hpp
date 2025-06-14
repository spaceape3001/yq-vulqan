////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ViewerCommand.hpp>
#include <tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiEnableKeyboardCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiEnableKeyboardCommand, ViewerCommand)
    public:
    
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
        ImGuiEnableKeyboardCommand(const Header&);
        
        static void init_info();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiEnableKeyboardCommand(const ImGuiEnableKeyboardCommand&, const Header&);
        virtual ~ImGuiEnableKeyboardCommand();

    private:
        ImGuiEnableKeyboardCommand(const ImGuiEnableKeyboardCommand&) = delete;
        ImGuiEnableKeyboardCommand(ImGuiEnableKeyboardCommand&&) = delete;
        ImGuiEnableKeyboardCommand& operator=(const ImGuiEnableKeyboardCommand&) = delete;
        ImGuiEnableKeyboardCommand& operator=(ImGuiEnableKeyboardCommand&&) = delete;
    };
}
