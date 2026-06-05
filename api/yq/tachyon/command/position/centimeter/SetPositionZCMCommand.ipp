////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻCMCommand)

namespace yq::tachyon {
    SetPositionᶻCMCommand::SetPositionᶻCMCommand(const Header&h, Centimeter z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionᶻCMCommand::SetPositionᶻCMCommand(const SetPositionᶻCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionᶻCMCommand::~SetPositionᶻCMCommand()
    {
    }
    
    PostCPtr    SetPositionᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionᶻCMCommand(*this, h);
    }

    void SetPositionᶻCMCommand::init_meta()
    {
        auto w = writer<SetPositionᶻCMCommand>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻCMCommand::z).tag(kTag_Log).tag(kTag_Save);
    }
}
