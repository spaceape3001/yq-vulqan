////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ATexture.hpp"
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/shape/SetTextureCommand.hpp>
#include <yq/tachyon/event/shape/SetTextureEvent.hpp>

namespace yq::tachyon {
    ATexture::ATexture()
    {
    }
    
    ATexture::~ATexture()
    {
    }

    TextureCPtr        ATexture::texture() const
    {
        return m_texture;
    }

    void        ATexture::texture(emit_k)
    {
        send(new SetTextureEvent({.source=typed()}, m_texture));
    }
    
    void        ATexture::texture(set_k, const TextureCPtr& mat) 
    {
        m_texture  =    mat;
        mark();
        texture(EMIT);
    }
    
    
    void        ATexture::on_set_texture(const SetTextureCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        texture(SET, cmd.texture());
    }
    
}
