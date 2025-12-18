////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetAutoCenterCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAutoCenterCommand)

namespace yq::tachyon {
    SetAutoCenterCommand::SetAutoCenterCommand(const Header& h, Tristate _autoCenter) : 
        ShapeCommand(h), m_autoCenter(_autoCenter)
    {
    }
    
    SetAutoCenterCommand::SetAutoCenterCommand(const SetAutoCenterCommand&cp, const Header&h) : 
        ShapeCommand(cp, h), m_autoCenter(cp.m_autoCenter)
    {
    }

    SetAutoCenterCommand::~SetAutoCenterCommand()
    {
    }
    
    PostCPtr    SetAutoCenterCommand::clone(rebind_k, const Header&h) const
    {
        return new SetAutoCenterCommand(*this, h);
    }

    void SetAutoCenterCommand::init_meta()
    {
        auto w = writer<SetAutoCenterCommand>();
        w.description("Set Auto Center Command");
        w.property("auto_center", &SetAutoCenterCommand::m_autoCenter);
    }
}
