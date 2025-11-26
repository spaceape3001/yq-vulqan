////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ITexture.hpp>

namespace yq::tachyon {
    class PTexture : public Proxy, public ITexture {
    public:
    
        virtual TextureCPtr texture() const override;
        virtual void        texture(set_k, const TextureCPtr&) override;
        virtual bool        texture(disabled_k) const override;
        virtual bool        texture(settable_k) const override;


        PTexture(const ITexture&);
        virtual ~PTexture();
        
    private:
        TextureCPtr    m_texture;
    };
}
