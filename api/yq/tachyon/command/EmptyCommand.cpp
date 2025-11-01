////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/EmptyCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

namespace yq::tachyon {
    EmptyCommand::EmptyCommand(const Param&p) : Command(p) 
    {
    }
    
    EmptyCommand::~EmptyCommand()
    {
    }
    
    void EmptyCommand::init_meta()
    {
        auto w = writer<EmptyCommand>();
        w.description("Empty Command");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::EmptyCommand)
