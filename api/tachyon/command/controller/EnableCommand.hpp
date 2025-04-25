////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ControllerCommand.hpp>

namespace yq::tachyon {
    class EnableCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(EnableCommand, ControllerCommand)
    public:
    
        EnableCommand(const Header&);

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();

    protected:

        EnableCommand(const EnableCommand&, const Header&);
        virtual ~EnableCommand();
        
    private:
        EnableCommand(const EnableCommand&) = delete;
        EnableCommand(EnableCommand&&) = delete;
        EnableCommand& operator=(const EnableCommand&) = delete;
        EnableCommand& operator=(EnableCommand&&) = delete;
    };
}
