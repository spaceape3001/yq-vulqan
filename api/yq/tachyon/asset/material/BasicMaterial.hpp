////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/typedef/color.hpp>
#include <yq/tachyon/asset/Material.hpp>

namespace yq::tachyon {
    //! Simple basic material, nothing fancy, might support roughness & metalic... 
    class BasicMaterial : public Material {
        YQ_RESOURCE_DECLARE(BasicMaterial, Material)
    public:
    
        RGBA4F  color;
    
        BasicMaterial(color_t);
        BasicMaterial();
        ~BasicMaterial();
        
        static void init_meta();
    };
}
