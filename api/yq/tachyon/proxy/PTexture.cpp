////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PTexture.hpp"
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/texture/SetTextureCommand.hpp>
#include <yq/tachyon/command/texture/SetTextureUrlCommand.hpp>

namespace yq::tachyon {
    PTexture::PTexture(const ITexture& i) : m_texture(i.texture()), m_url(i.texture(URL))
    {
        if(i.texture(DISABLED))
            m_flags |= F::Disabled;
        if(i.texture(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PTexture::~PTexture()
    {
    }

    TextureCPtr    PTexture::texture() const
    {
        return m_texture;
    }
    
    Url     PTexture::texture(url_k) const
    {
        return m_url;
    }
    
    void    PTexture::texture(set_k, const TextureCPtr& tex) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetTextureCommand({.target=object()}, tex));
        }
    }
    
    void    PTexture::texture(set_k, const Url& u)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetTextureUrlCommand({.target=object()}, u));
        }
    }
    
    bool    PTexture::texture(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool    PTexture::texture(settable_k) const 
    {
        return m_flags(F::Settable);
    }
}
