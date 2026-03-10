////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionZMCommand)

namespace yq::tachyon {
    SetPositionZMCommand::SetPositionZMCommand(const Header&h, Meter z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionZMCommand::SetPositionZMCommand(const SetPositionZMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionZMCommand::~SetPositionZMCommand()
    {
    }
    
    PostCPtr    SetPositionZMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionZMCommand(*this, h);
    }

    void SetPositionZMCommand::init_meta()
    {
        auto w = writer<SetPositionZMCommand>();
        w.description("Set Position Command");
        w.property("z", &SetPositionZMCommand::z).tag(kTag_Log).tag(kTag_Save);
    }
}
