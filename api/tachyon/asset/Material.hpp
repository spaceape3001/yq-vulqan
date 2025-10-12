////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/material.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! "Material" specification (file)
        
        This is a typical material specification, can be used to create a material (later/TBD)
    */
    class Material : public Resource {
        YQ_RESOURCE_DECLARE(Material, Resource)
    public:
        // TODO (Contents)
    
        Material();
        ~Material();
        static void init_meta();
    };
}
