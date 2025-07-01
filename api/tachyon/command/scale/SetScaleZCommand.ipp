////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/SetScaleZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleᶻCommand)

namespace yq::tachyon {
    SetScaleᶻCommand::SetScaleᶻCommand(const Header&h, double z) : 
        ScaleCommand(h), m_z(z)
    {
    }
    
    SetScaleᶻCommand::SetScaleᶻCommand(const SetScaleᶻCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_z(cp.m_z)
    {
    }

    SetScaleᶻCommand::~SetScaleᶻCommand()
    {
    }

    PostCPtr    SetScaleᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleᶻCommand(*this, h);
    }
    
    void SetScaleᶻCommand::init_meta()
    {
        auto w = writer<SetScaleᶻCommand>();
        w.description("Set Scale Command");
        w.property("z", &SetScaleᶻCommand::z);
    }
}
