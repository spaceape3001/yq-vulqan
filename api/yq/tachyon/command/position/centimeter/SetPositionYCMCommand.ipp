////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionYCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸCMCommand)

namespace yq::tachyon {
    SetPositionʸCMCommand::SetPositionʸCMCommand(const Header&h, Centimeter y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionʸCMCommand::SetPositionʸCMCommand(const SetPositionʸCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionʸCMCommand::~SetPositionʸCMCommand()
    {
    }
    
    PostCPtr    SetPositionʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionʸCMCommand(*this, h);
    }

    void SetPositionʸCMCommand::init_meta()
    {
        auto w = writer<SetPositionʸCMCommand>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸCMCommand::y).tag(kTag_Log).tag(kTag_Save);
    }
}
