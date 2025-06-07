////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionʸCommand)

namespace yq::tachyon {
    SetPositionʸCommand::SetPositionʸCommand(const Header&h, double y) : 
        PositionCommand(h), m_y(y)
    {
    }

    SetPositionʸCommand::SetPositionʸCommand(const SetPositionʸCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetPositionʸCommand::~SetPositionʸCommand()
    {
    }
    
    PostCPtr    SetPositionʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionʸCommand(*this, h);
    }

    void SetPositionʸCommand::init_info()
    {
        auto w = writer<SetPositionʸCommand>();
        w.description("Set Position Command");
        w.property("y", &SetPositionʸCommand::y);
    }
}
