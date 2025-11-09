////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/command/ExecuteStringCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteStringCommand)

namespace yq::lua {

    ExecuteStringCommand::ExecuteStringCommand(const Header&h, std::string_view v) : LuaCommand(h), m_text(v)
    {
    }

    ExecuteStringCommand::ExecuteStringCommand(const ExecuteStringCommand& cp, const Header& h) : 
        LuaCommand(cp, h), m_text(cp.m_text)
    {
    }
    
    ExecuteStringCommand::~ExecuteStringCommand()
    {
    }

    tachyon::PostCPtr    ExecuteStringCommand::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteStringCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteStringCommand::init_meta()
    {
        auto w = writer<ExecuteStringCommand>();
        w.description("Lua Execute String Command");
        w.property("text", &ExecuteStringCommand::m_text);
    }
}
