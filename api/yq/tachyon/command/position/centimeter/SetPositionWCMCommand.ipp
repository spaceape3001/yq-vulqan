////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionWCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʷCMCommand)

namespace yq::tachyon {
    SetPositionʷCMCommand::SetPositionʷCMCommand(const Header&h, Centimeter w) : 
        PositionCommand(h), m_w(w)
    {
    }
    
    SetPositionʷCMCommand::SetPositionʷCMCommand(const SetPositionʷCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetPositionʷCMCommand::~SetPositionʷCMCommand()
    {
    }

    PostCPtr    SetPositionʷCMCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionʷCMCommand(*this, h);
    }
    
    void SetPositionʷCMCommand::init_meta()
    {
        auto w = writer<SetPositionʷCMCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPositionʷCMCommand::m_w).tag(kTag_Save).tag(kTag_Log);
    }
}
