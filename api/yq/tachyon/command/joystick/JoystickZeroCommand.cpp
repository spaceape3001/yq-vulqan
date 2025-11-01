////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/joystick/JoystickZeroCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

namespace yq::tachyon {
    void JoystickZeroCommand::init_meta()
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
