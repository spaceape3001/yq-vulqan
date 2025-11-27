////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/typedef/url.hpp>

namespace yq::tachyon {
    class PTexture;
    
    class ITexture {
    public:
        YQ_INTERFACE_DECLARE(ITexture, PTexture)

        virtual TextureCPtr texture() const = 0;
        virtual Url         texture(url_k) const = 0;
        virtual void        texture(set_k, const TextureCPtr&){}
        virtual void        texture(set_k, const Url&){}

        virtual bool        texture(disabled_k) const { return false; }
        virtual bool        texture(settable_k) const { return false; }

        static void init_meta();
    };
}
