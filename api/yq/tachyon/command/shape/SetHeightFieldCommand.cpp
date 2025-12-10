////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetHeightFieldCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/asset/HeightField.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeightFieldCommand)

namespace yq::tachyon {

    SetHeightFieldCommand::SetHeightFieldCommand(const Header&h, const HeightFieldCPtr& dm) : ShapeCommand(h), m_heightField(dm)
    {
    }

    SetHeightFieldCommand::SetHeightFieldCommand(const SetHeightFieldCommand& cp, const Header& h) : 
        ShapeCommand(cp, h), m_heightField(cp.m_heightField)
    {
    }
    
    SetHeightFieldCommand::~SetHeightFieldCommand()
    {
    }

    PostCPtr    SetHeightFieldCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetHeightFieldCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetHeightFieldCommand::init_meta()
    {
        auto w = writer<SetHeightFieldCommand>();
        w.description("Set Height Field Command");
    }
}
