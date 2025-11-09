////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/command/ExecuteFileCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteFileCommand)

namespace yq::lua {

    ExecuteFileCommand::ExecuteFileCommand(const Header&h, const std::filesystem::path& v) : LuaCommand(h), m_file(v)
    {
    }

    ExecuteFileCommand::ExecuteFileCommand(const ExecuteFileCommand& cp, const Header& h) : 
        LuaCommand(cp, h), m_file(cp.m_file)
    {
    }
    
    ExecuteFileCommand::~ExecuteFileCommand()
    {
    }

    tachyon::PostCPtr    ExecuteFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteFileCommand::init_meta()
    {
        auto w = writer<ExecuteFileCommand>();
        w.description("Lua Execute File Command");
        //w.property("file", &ExecuteFileCommand::m_file);  // TODO (file as an any)
    }
}
