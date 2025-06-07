////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣCommand)

namespace yq::tachyon {
    SetPositionˣCommand::SetPositionˣCommand(const Header&h, double x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionˣCommand::SetPositionˣCommand(const SetPositionˣCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionˣCommand::~SetPositionˣCommand()
    {
    }

    PostCPtr    SetPositionˣCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionˣCommand(*this, h);
    }
    
    void SetPositionˣCommand::init_info()
    {
        auto w = writer<SetPositionˣCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣCommand::x);
    }
}
