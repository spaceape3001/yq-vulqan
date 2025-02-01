////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/SetParentCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

namespace yq::tachyon {
    SetParentCommand::SetParentCommand(TachyonID tac, TachyonID parentID, const Param& p) :
        Command(p), TachyonBind(tac), m_parent(parentID)
    {
    }
    
    SetParentCommand::~SetParentCommand()
    {
    }
        
    void SetParentCommand::init_info()
    {
        auto w = writer<SetParentCommand>();
        w.description("Set Parent Command");
    }
}

YQ_OBJECT_IMPLEMENT(SetParentCommand)
