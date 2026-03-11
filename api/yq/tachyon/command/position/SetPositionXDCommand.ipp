////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionXDCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣDCommand)

namespace yq::tachyon {
    SetPositionˣDCommand::SetPositionˣDCommand(const Header&h, double x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionˣDCommand::SetPositionˣDCommand(const SetPositionˣDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionˣDCommand::~SetPositionˣDCommand()
    {
    }

    PostCPtr    SetPositionˣDCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionˣDCommand(*this, h);
    }
    
    void SetPositionˣDCommand::init_meta()
    {
        auto w = writer<SetPositionˣDCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣDCommand::x).tag(kTag_Save).tag(kTag_Log);
    }
}
