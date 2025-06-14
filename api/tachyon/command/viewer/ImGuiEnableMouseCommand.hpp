////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ViewerCommand.hpp>
#include <tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiEnableMouseCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiEnableMouseCommand, ViewerCommand)
    public:
    
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
        ImGuiEnableMouseCommand(const Header&);
        
        static void init_info();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiEnableMouseCommand(const ImGuiEnableMouseCommand&, const Header&);
        virtual ~ImGuiEnableMouseCommand();

    private:
        ImGuiEnableMouseCommand(const ImGuiEnableMouseCommand&) = delete;
        ImGuiEnableMouseCommand(ImGuiEnableMouseCommand&&) = delete;
        ImGuiEnableMouseCommand& operator=(const ImGuiEnableMouseCommand&) = delete;
        ImGuiEnableMouseCommand& operator=(ImGuiEnableMouseCommand&&) = delete;
    };
}
