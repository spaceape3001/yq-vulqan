////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/GamepadCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadCommand)

namespace yq::tachyon {
    GamepadCommand::GamepadCommand(const Header& h) : Command(h)
    {
    }
    
    GamepadCommand::GamepadCommand(const GamepadCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    GamepadCommand::~GamepadCommand()
    {
    }
    
    void GamepadCommand::init_info()
    {
        auto w = writer<GamepadCommand>();
        w.abstract();
        w.description("Gamepad Command");
    }
}
