////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTextureCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/asset/Texture.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTextureCommand)

namespace yq::tachyon {

    SetTextureCommand::SetTextureCommand(const Header&h, const TextureCPtr& dm) : ShapeCommand(h), m_texture(dm)
    {
    }

    SetTextureCommand::SetTextureCommand(const SetTextureCommand& cp, const Header& h) : 
        ShapeCommand(cp, h), m_texture(cp.m_texture)
    {
    }
    
    SetTextureCommand::~SetTextureCommand()
    {
    }

    PostCPtr    SetTextureCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetTextureCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetTextureCommand::init_meta()
    {
        auto w = writer<SetTextureCommand>();
        w.description("Set Texture Command");
    }
}
