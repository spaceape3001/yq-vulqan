////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ControllerCommand.hpp>

namespace yq::tachyon {
    class DisableCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(DisableCommand, ControllerCommand)
    public:
    
        DisableCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        DisableCommand(const DisableCommand&, const Header&);
        virtual ~DisableCommand();
        
    private:
        DisableCommand(const DisableCommand&) = delete;
        DisableCommand(DisableCommand&&) = delete;
        DisableCommand& operator=(const DisableCommand&) = delete;
        DisableCommand& operator=(DisableCommand&&) = delete;
    };
}
