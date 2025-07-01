////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻCommand)

namespace yq::tachyon {
    SetPositionᶻCommand::SetPositionᶻCommand(const Header&h, double z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionᶻCommand::SetPositionᶻCommand(const SetPositionᶻCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionᶻCommand::~SetPositionᶻCommand()
    {
    }
    
    PostCPtr    SetPositionᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionᶻCommand(*this, h);
    }

    void SetPositionᶻCommand::init_meta()
    {
        auto w = writer<SetPositionᶻCommand>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻCommand::z);
    }
}
