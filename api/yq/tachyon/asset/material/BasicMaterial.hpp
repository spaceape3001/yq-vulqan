////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/typedef/color.hpp>
#include <yq/tachyon/asset/Material.hpp>

namespace yq::tachyon {
    /*! Simple basic material, nothing fancy
    
        \note While we do have this distinction, it's not recommended to expose
            that to the end user; drivers should generally promise on the material
            level for loading, dealing with the various complexities... saving 
            could be more specific.
    */
    class BasicMaterial : public Material {
        YQ_RESOURCE_DECLARE(BasicMaterial, Material)
    public:
    
        RGBA4F          color;
        float           roughness       = 0;
        float           metallic        = 0;
    
        BasicMaterial(const color_t&);
        BasicMaterial();
        ~BasicMaterial();
        
        static void init_meta();
    };
}
