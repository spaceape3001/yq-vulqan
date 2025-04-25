////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/JoystickCommand.hpp>

namespace yq::tachyon {
    class JoystickZeroCommand : public JoystickCommand {
        YQ_OBJECT_DECLARE(JoystickZeroCommand, JoystickCommand);
    public:
        static void init_info();
    
        JoystickZeroCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickZeroCommand(const JoystickZeroCommand&, const Header&);
        ~JoystickZeroCommand();
        
    private:
        JoystickZeroCommand(const JoystickZeroCommand&) = delete;
        JoystickZeroCommand(JoystickZeroCommand&&) = delete;
        JoystickZeroCommand& operator=(const JoystickZeroCommand&) = delete;
        JoystickZeroCommand& operator=(JoystickZeroCommand&&) = delete;
    };
}
