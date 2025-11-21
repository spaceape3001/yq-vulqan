////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/command/LuaCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaCommand)

namespace yq::tachyon {
    LuaCommand::LuaCommand(const Header& h) : Command(h)
    {
    }
    
    LuaCommand::LuaCommand(const LuaCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    LuaCommand::~LuaCommand()
    {
    }
    
    void LuaCommand::init_meta()
    {
        auto w = writer<LuaCommand>();
        w.abstract();
        w.description("Lua Command");
    }
}
