////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PTexture.hpp"
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/shape/SetTextureCommand.hpp>

namespace yq::tachyon {
    PTexture::PTexture(const ITexture& i) : m_texture(i.texture())
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
    
    void    PTexture::texture(set_k, const TextureCPtr& tex) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetTextureCommand({.target=object()}, tex));
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
