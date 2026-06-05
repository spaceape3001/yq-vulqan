////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionWMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʷMCommand)

namespace yq::tachyon {
    SetPositionʷMCommand::SetPositionʷMCommand(const Header&h, Meter w) : 
        PositionCommand(h), m_w(w)
    {
    }
    
    SetPositionʷMCommand::SetPositionʷMCommand(const SetPositionʷMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetPositionʷMCommand::~SetPositionʷMCommand()
    {
    }

    PostCPtr    SetPositionʷMCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionʷMCommand(*this, h);
    }
    
    void SetPositionʷMCommand::init_meta()
    {
        auto w = writer<SetPositionʷMCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPositionʷMCommand::m_w).tag(kTag_Save).tag(kTag_Log);
    }
}
