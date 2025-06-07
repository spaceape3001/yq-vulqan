////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionWCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʷCommand)

namespace yq::tachyon {
    SetPositionʷCommand::SetPositionʷCommand(const Header&h, double w) : 
        PositionCommand(h), m_w(w)
    {
    }
    
    SetPositionʷCommand::SetPositionʷCommand(const SetPositionʷCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetPositionʷCommand::~SetPositionʷCommand()
    {
    }

    PostCPtr    SetPositionʷCommand::clone(rebind_k, const Header& h) const
    {
        return new SetPositionʷCommand(*this, h);
    }
    
    void SetPositionʷCommand::init_info()
    {
        auto w = writer<SetPositionʷCommand>();
        w.description("Set Position Command");
        w.property("w", &SetPositionʷCommand::m_w);
    }
}
