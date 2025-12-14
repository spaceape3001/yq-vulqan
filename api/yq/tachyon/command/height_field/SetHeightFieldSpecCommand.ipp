////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetHeightFieldSpecCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeightFieldSpecCommand)

namespace yq::tachyon {

    SetHeightFieldSpecCommand::SetHeightFieldSpecCommand(const Header&h, const std::string& dm) : HeightFieldCommand(h), m_spec(dm)
    {
    }

    SetHeightFieldSpecCommand::SetHeightFieldSpecCommand(const SetHeightFieldSpecCommand& cp, const Header& h) : 
        HeightFieldCommand(cp, h), m_spec(cp.m_spec)
    {
    }
    
    SetHeightFieldSpecCommand::~SetHeightFieldSpecCommand()
    {
    }

    PostCPtr    SetHeightFieldSpecCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetHeightFieldSpecCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetHeightFieldSpecCommand::init_meta()
    {
        auto w = writer<SetHeightFieldSpecCommand>();
        w.description("Set Height Field Spec Command");
        w.property("spec", &SetHeightFieldSpecCommand::m_spec);
    }
}
