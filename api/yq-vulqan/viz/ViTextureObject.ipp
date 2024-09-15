////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViTextureObject.hpp"
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/viz/ViTexture.hpp>

namespace yq::tachyon {
    bool    ViTextureObject::update(ViVisualizer&viz, const TexConfig&cfg, const void*p)
    {
        do {
            if(!cfg.fetch)
                return false;
            if(p ? (cfg.activity == DataActivity::COMMON) : (cfg.activity != DataActivity::COMMON))
                return false;
            if(!view || !sampler)                                 // LOAD
                break;
            if(cfg.activity != DataActivity::DYNAMIC)   // LOAD
                break;
            if(!cfg.revision)
                return false;
            
            uint64_t    n   = cfg.revision(p);
            if(n == rev)
                return false;
            rev    = n;
        } while(false);
        
        TextureCPtr   c   = cfg.fetch(p);
        if(!c){     //  shouldn't really happen....
            yWarning() << "EMPTY TEXTURE DETECTED!";
            return false;
        }
        
        ViTextureCPtr xvb    = viz.texture_create(*c);
        if(xvb && xvb->valid()){
            view    = xvb->image_view();
            sampler = xvb->sampler();
            return true;
        } else {
            yWarning() << "TEXTURE CREATION FAILED!";
        }
        
        return false;
    }

}
