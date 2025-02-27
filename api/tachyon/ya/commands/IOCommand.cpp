////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/IOCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IOCommand)

namespace yq::tachyon {
    IOCommand::IOCommand(const Header& h) : Command(h)
    {
    }
    
    IOCommand::IOCommand(const IOCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    IOCommand::~IOCommand()
    {
    }
    
    void IOCommand::init_info()
    {
        auto w = writer<IOCommand>();
        w.abstract();
        w.description("IO Command");
    }
}
