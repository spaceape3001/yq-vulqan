////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/LightCommand.hpp>

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightCommand)

namespace yq::tachyon {
    LightCommand::LightCommand(const Header&h) : Command(h)
    {
    }

    LightCommand::LightCommand(const LightCommand& cp, const Header& h) : Command(cp, h)
    {
        // DEPRECATED
    }
    
    LightCommand::~LightCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LightCommand::init_info()
    {
        auto w = writer<LightCommand>();
        w.description("Light command base class");
    }
}
