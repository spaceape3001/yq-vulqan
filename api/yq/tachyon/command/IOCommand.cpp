////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/IOCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

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
    
    void IOCommand::init_meta()
    {
        auto w = writer<IOCommand>();
        w.abstract();
        w.description("IO Command");
    }
}
