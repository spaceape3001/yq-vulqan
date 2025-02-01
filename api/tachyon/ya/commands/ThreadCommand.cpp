////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ThreadCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadCommand)

namespace yq::tachyon {
    ThreadCommand::ThreadCommand(const Header& h) : Command(h)
    {
    }
    
    ThreadCommand::ThreadCommand(const ThreadCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    ThreadCommand::~ThreadCommand()
    {
    }
    
    void ThreadCommand::init_info()
    {
        auto w = writer<ThreadCommand>();
        w.abstract();
        w.description("Thread Command");
    }
}
