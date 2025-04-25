////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/joystick/JoystickZeroCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickZeroCommand::init_info()
    {
        auto w = writer<JoystickZeroCommand>();
        w.description("Joystick Zeroion Command");
    }

    JoystickZeroCommand::JoystickZeroCommand(const Header&h) : JoystickCommand(h)
    {
    }
    
    JoystickZeroCommand::JoystickZeroCommand(const JoystickZeroCommand& cp, const Header&h) : JoystickCommand(cp, h)
    {
    }

    JoystickZeroCommand::~JoystickZeroCommand()
    {
    }

    PostCPtr    JoystickZeroCommand::clone(rebind_k, const Header&h) const
    {
        return new JoystickZeroCommand(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickZeroCommand)
