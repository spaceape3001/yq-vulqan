////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/tachyon/typedef/material.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! "Material" specification (file)
        
        This is a material specification, can be used for 
        shapes.  Merging wavefront Obj & GLTF specifications into
        a singular spec.
    */
    class Material : public Resource {
        YQ_RESOURCE_DECLARE(Material, Resource)
    public:
    
        Tristate    double_sided    = Tristate::Inherit;
    
            // this will be a derived class situation
            
        Material();
        ~Material();
        static void init_meta();
    };
}
