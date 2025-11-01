////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiDisableMouseCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiDisableMouseCommand, ViewerCommand)
    public:
    
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
        ImGuiDisableMouseCommand(const Header&);
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        ImGuiDisableMouseCommand(const ImGuiDisableMouseCommand&, const Header&);
        virtual ~ImGuiDisableMouseCommand();

    private:
        ImGuiDisableMouseCommand(const ImGuiDisableMouseCommand&) = delete;
        ImGuiDisableMouseCommand(ImGuiDisableMouseCommand&&) = delete;
        ImGuiDisableMouseCommand& operator=(const ImGuiDisableMouseCommand&) = delete;
        ImGuiDisableMouseCommand& operator=(ImGuiDisableMouseCommand&&) = delete;
    };
}
