////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/command/LuaCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaCommand)

namespace yq::lua {
    LuaCommand::LuaCommand(const Header& h) : tachyon::Command(h)
    {
    }
    
    LuaCommand::LuaCommand(const LuaCommand&cp, const Header&h) : tachyon::Command(cp, h)
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
