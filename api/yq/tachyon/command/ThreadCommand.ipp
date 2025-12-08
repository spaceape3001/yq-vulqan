////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ThreadCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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
    
    void ThreadCommand::init_meta()
    {
        auto w = writer<ThreadCommand>();
        w.abstract();
        w.description("Thread Command");
    }
}
