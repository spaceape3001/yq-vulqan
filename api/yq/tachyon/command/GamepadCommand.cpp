////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/GamepadCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

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
    
    void GamepadCommand::init_meta()
    {
        auto w = writer<GamepadCommand>();
        w.abstract();
        w.description("Gamepad Command");
    }
}
