////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/material_spec.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! "MaterialSpec" specification (file)
        
        This is a typical material specification, can be used to create a material (later/TBD)
    */
    class MaterialSpec : public Resource {
        YQ_RESOURCE_DECLARE(MaterialSpec, Resource)
    public:
        // TODO (Contents)
    
        MaterialSpec();
        ~MaterialSpec();
        static void init_meta();
    };
}
