////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class ImGuiEnableMouseCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ImGuiEnableMouseCommand, ViewerCommand)
    public:
    
        ImGuiEnableMouseCommand(const Header&);
        
        static void init_meta();
        
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
