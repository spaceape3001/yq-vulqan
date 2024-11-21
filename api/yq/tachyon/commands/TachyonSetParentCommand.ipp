////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonSetParentCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

namespace yq::tachyon {
    TachyonSetParentCommand::TachyonSetParentCommand(TachyonID tac, TachyonID parentID, const Param& p) :
        TachyonCommand(tac, p), m_parent(parentID)
    {
    }
    
    TachyonSetParentCommand::~TachyonSetParentCommand()
    {
    }
        
    void TachyonSetParentCommand::init_info()
    {
        auto w = writer<TachyonSetParentCommand>();
        w.description("Set Tachyon Parent Command");
    }
}

YQ_OBJECT_IMPLEMENT(TachyonSetParentCommand)
