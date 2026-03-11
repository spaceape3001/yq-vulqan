////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionYDCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸDCommand)

namespace yq::tachyon {
    SetPositionʸDCommand::SetPositionʸDCommand(const Header&h, double y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionʸDCommand::SetPositionʸDCommand(const SetPositionʸDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionʸDCommand::~SetPositionʸDCommand()
    {
    }
    
    PostCPtr    SetPositionʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionʸDCommand(*this, h);
    }

    void SetPositionʸDCommand::init_meta()
    {
        auto w = writer<SetPositionʸDCommand>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸDCommand::y).tag(kTag_Save).tag(kTag_Log);
    }
}
