////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionWDCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʷDCommand)

namespace yq::tachyon {
    SetPositionʷDCommand::SetPositionʷDCommand(const Header&h, double w) : 
        PositionCommand(h), m_w(w)
    {
    }
    
    SetPositionʷDCommand::SetPositionʷDCommand(const SetPositionʷDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetPositionʷDCommand::~SetPositionʷDCommand()
    {
    }

    PostCPtr    SetPositionʷDCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionʷDCommand(*this, h);
    }
    
    void SetPositionʷDCommand::init_meta()
    {
        auto w = writer<SetPositionʷDCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPositionʷDCommand::m_w).tag(kTag_Save).tag(kTag_Log);
    }
}
