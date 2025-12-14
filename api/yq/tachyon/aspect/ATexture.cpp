////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ATexture.hpp"
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/texture/SetTextureCommand.hpp>
#include <yq/tachyon/command/texture/SetTextureSpecCommand.hpp>
#include <yq/tachyon/command/texture/SetTextureUrlCommand.hpp>
#include <yq/tachyon/event/SetTextureEvent.hpp>

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

    Url         ATexture::texture(url_k) const 
    {
        return m_textureUrl;
    }

    void        ATexture::texture(emit_k)
    {
        send(new SetTextureEvent({.source=typed()}, m_texture, m_textureUrl));
    }
    
    void        ATexture::texture(set_k, const TextureCPtr& tex) 
    {
        m_texture           = tex;
        m_textureUrl        = tex ? tex->url() : Url();
        mark();
        texture(EMIT);
    }
    
    void        ATexture::texture(set_k, const Url& u)
    {
        m_textureUrl    = u;
        if(u.empty()){
            m_texture   = {};
        } else {
            m_texture   = Texture::IO::load(u);
        }
        mark();
        texture(EMIT);
    }
    
    void        ATexture::on_set_texture(const SetTextureCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        texture(SET, cmd.texture());
    }

    void        ATexture::on_set_texture_spec(const SetTextureSpecCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
        texture(SET, Resource::resolve(cmd.spec()));
    }
    
    void        ATexture::on_set_texture_url(const SetTextureUrlCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        texture(SET, cmd.url());
    }
}
