////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetColorProfileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/asset/ColorProfile.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetColorProfileCommand)

namespace yq::tachyon {

    SetColorProfileCommand::SetColorProfileCommand(const Header&h, const ColorProfileCPtr& dm) : ColorProfileCommand(h), m_colorProfile(dm)
    {
    }

    SetColorProfileCommand::SetColorProfileCommand(const SetColorProfileCommand& cp, const Header& h) : 
        ColorProfileCommand(cp, h), m_colorProfile(cp.m_colorProfile)
    {
    }
    
    SetColorProfileCommand::~SetColorProfileCommand()
    {
    }

    PostCPtr    SetColorProfileCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetColorProfileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetColorProfileCommand::init_meta()
    {
        auto w = writer<SetColorProfileCommand>();
        w.description("Set ColorProfile Command");
    }
}
