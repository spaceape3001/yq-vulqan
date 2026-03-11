////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZDCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻDCommand)

namespace yq::tachyon {
    SetPositionᶻDCommand::SetPositionᶻDCommand(const Header&h, double z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionᶻDCommand::SetPositionᶻDCommand(const SetPositionᶻDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionᶻDCommand::~SetPositionᶻDCommand()
    {
    }
    
    PostCPtr    SetPositionᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionᶻDCommand(*this, h);
    }

    void SetPositionᶻDCommand::init_meta()
    {
        auto w = writer<SetPositionᶻDCommand>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻDCommand::z).tag(kTag_Save).tag(kTag_Log);
    }
}
