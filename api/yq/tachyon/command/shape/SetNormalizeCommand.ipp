////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetNormalizeCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetNormalizeCommand)

namespace yq::tachyon {
    SetNormalizeCommand::SetNormalizeCommand(const Header& h, Tristate _normalize) : 
        ShapeCommand(h), m_normalize(_normalize)
    {
    }
    
    SetNormalizeCommand::SetNormalizeCommand(const SetNormalizeCommand&cp, const Header&h) : 
        ShapeCommand(cp, h), m_normalize(cp.m_normalize)
    {
    }

    SetNormalizeCommand::~SetNormalizeCommand()
    {
    }
    
    PostCPtr    SetNormalizeCommand::clone(rebind_k, const Header&h) const
    {
        return new SetNormalizeCommand(*this, h);
    }

    void SetNormalizeCommand::init_meta()
    {
        auto w = writer<SetNormalizeCommand>();
        w.description("Set Auto Center Command");
        w.property("normalize", &SetNormalizeCommand::m_normalize);
    }
}
