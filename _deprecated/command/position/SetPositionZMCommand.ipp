////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻMCommand)

namespace yq::tachyon {
    SetPositionᶻMCommand::SetPositionᶻMCommand(const Header&h, Meter z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionᶻMCommand::SetPositionᶻMCommand(const SetPositionᶻMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionᶻMCommand::~SetPositionᶻMCommand()
    {
    }
    
    PostCPtr    SetPositionᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionᶻMCommand(*this, h);
    }

    void SetPositionᶻMCommand::init_meta()
    {
        auto w = writer<SetPositionᶻMCommand>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻMCommand::z).tag(kTag_Log).tag(kTag_Save);
    }
}
