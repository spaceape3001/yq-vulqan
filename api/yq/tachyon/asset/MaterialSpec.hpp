////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/material_spec.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {

    /*! "MaterialSpec" specification (file)
        
        This is a typical material specification, can be used to create a material (later/TBD)
    */
    class MaterialSpec : public Resource {
        YQ_RESOURCE_DECLARE(MaterialSpec, Resource)
    public:
        // TODO (Contents)
    
        bool                double_sided = false;
        RGB3D               emmisive_factor{0., 0., 0.};
        std::vector<int>    lods;
    
        MaterialSpec();
        ~MaterialSpec();
        static void init_meta();
    };
}
