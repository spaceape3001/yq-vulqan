////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/MouseCommand.hpp>

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseCommand)

namespace yq::tachyon {
    MouseCommand::MouseCommand(const Header&h) : Command(h)
    {
    }

    MouseCommand::MouseCommand(const MouseCommand& cp, const Header&h) : Command(cp, h)
    {
    }

    MouseCommand::~MouseCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseCommand::init_info()
    {
        auto w = writer<MouseCommand>();
        w.description("Mouse command base class");
    }
}
