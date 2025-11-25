////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/material.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {

    /*! "Material" specification (file)
        
        This is a typical material specification, can be used to create a material (later/TBD)
    */
    class Material : public Resource {
        YQ_RESOURCE_DECLARE(Material, Resource)
    public:
        // TODO (Contents)
    
        bool                double_sided = false;
        RGB3D               emmisive_factor{0., 0., 0.};
        std::vector<int>    lods;
    
        Material();
        ~Material();
        static void init_meta();
    };
}
