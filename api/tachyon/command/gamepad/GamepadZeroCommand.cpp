////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/gamepad/GamepadZeroCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

namespace yq::tachyon {
    void GamepadZeroCommand::init_info()
    {
        auto w = writer<GamepadZeroCommand>();
        w.description("Gamepad Zeroion Command");
    }

    GamepadZeroCommand::GamepadZeroCommand(const Header&h) : GamepadCommand(h)
    {
    }
    
    GamepadZeroCommand::GamepadZeroCommand(const GamepadZeroCommand& cp, const Header&h) : GamepadCommand(cp, h)
    {
    }

    GamepadZeroCommand::~GamepadZeroCommand()
    {
    }

    PostCPtr    GamepadZeroCommand::clone(rebind_k, const Header&h) const
    {
        return new GamepadZeroCommand(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadZeroCommand)
