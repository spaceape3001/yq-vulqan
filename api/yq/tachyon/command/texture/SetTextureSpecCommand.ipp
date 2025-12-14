////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTextureSpecCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTextureSpecCommand)

namespace yq::tachyon {

    SetTextureSpecCommand::SetTextureSpecCommand(const Header&h, const std::string& dm) : TextureCommand(h), m_spec(dm)
    {
    }

    SetTextureSpecCommand::SetTextureSpecCommand(const SetTextureSpecCommand& cp, const Header& h) : 
        TextureCommand(cp, h), m_spec(cp.m_spec)
    {
    }
    
    SetTextureSpecCommand::~SetTextureSpecCommand()
    {
    }

    PostCPtr    SetTextureSpecCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetTextureSpecCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetTextureSpecCommand::init_meta()
    {
        auto w = writer<SetTextureSpecCommand>();
        w.description("Set Texture Spec Command");
        w.property("spec", &SetTextureSpecCommand::m_spec);
    }
}
