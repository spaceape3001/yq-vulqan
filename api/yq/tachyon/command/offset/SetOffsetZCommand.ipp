////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffsetZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffsetᶻCommand)

namespace yq::tachyon {
    SetOffsetᶻCommand::SetOffsetᶻCommand(const Header&h, double z) : 
        OffsetCommand(h), m_z(z)
    {
    }

    SetOffsetᶻCommand::SetOffsetᶻCommand(const SetOffsetᶻCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetOffsetᶻCommand::~SetOffsetᶻCommand()
    {
    }
    
    PostCPtr    SetOffsetᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetOffsetᶻCommand(*this, h);
    }

    void SetOffsetᶻCommand::init_meta()
    {
        auto w = writer<SetOffsetᶻCommand>();
        w.description("Set Offset Command");
        w.property("z", &SetOffsetᶻCommand::z);
    }
}
