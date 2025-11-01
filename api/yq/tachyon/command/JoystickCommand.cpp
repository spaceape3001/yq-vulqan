////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/JoystickCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickCommand)

namespace yq::tachyon {
    JoystickCommand::JoystickCommand(const Header& h) : Command(h)
    {
    }
    
    JoystickCommand::JoystickCommand(const JoystickCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    JoystickCommand::~JoystickCommand()
    {
    }
    
    void JoystickCommand::init_meta()
    {
        auto w = writer<JoystickCommand>();
        w.abstract();
        w.description("Joystick Command");
    }
}
