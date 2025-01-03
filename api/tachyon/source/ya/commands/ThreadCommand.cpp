////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ThreadCommand.hpp>

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadCommand)

namespace yq::tachyon {
    ThreadCommandInfo::ThreadCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ThreadCommand::ThreadCommand(ThreadID v, const Param& p) : Command(p), ThreadBind(v)
    {
    }
    
    ThreadCommand::~ThreadCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ThreadCommand::init_info()
    {
        auto w = writer<ThreadCommand>();
        w.description("Thread command base class");
    }
}
