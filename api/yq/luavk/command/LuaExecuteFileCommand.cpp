////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaExecuteFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaExecuteFileCommand)

namespace yq::tachyon {

    LuaExecuteFileCommand::LuaExecuteFileCommand(const Header&h, const std::filesystem::path& v) : LuaCommand(h), m_file(v)
    {
    }

    LuaExecuteFileCommand::LuaExecuteFileCommand(const LuaExecuteFileCommand& cp, const Header& h) : 
        LuaCommand(cp, h), m_file(cp.m_file)
    {
    }
    
    LuaExecuteFileCommand::~LuaExecuteFileCommand()
    {
    }

    tachyon::PostCPtr    LuaExecuteFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new LuaExecuteFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LuaExecuteFileCommand::init_meta()
    {
        auto w = writer<LuaExecuteFileCommand>();
        w.description("Lua LuaExecute File Command");
        //w.property("file", &LuaExecuteFileCommand::m_file);  // TODO (file as an any)
    }
}
