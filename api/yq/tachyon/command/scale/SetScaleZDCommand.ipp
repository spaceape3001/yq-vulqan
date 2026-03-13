////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleᶻDCommand)

namespace yq::tachyon {
    SetScaleᶻDCommand::SetScaleᶻDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_z(z)
    {
    }
    
    SetScaleᶻDCommand::SetScaleᶻDCommand(const SetScaleᶻDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_z(cp.m_z)
    {
    }

    SetScaleᶻDCommand::~SetScaleᶻDCommand()
    {
    }

    PostCPtr    SetScaleᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleᶻDCommand(*this, h);
    }
    
    void SetScaleᶻDCommand::init_meta()
    {
        auto w = writer<SetScaleᶻDCommand>();
        w.description("Set Scale Command");
        w.property("z", &SetScaleᶻDCommand::z);
    }
}
