////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/light_spec.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! \brief Light specification/configuration
    
        This is data from the file, can be used to create actual light sources.
        
        \note Named to not conflict with the tachyon (so that a GLTF won't accidentally instantiate one)
    */
    class LightSpec : public Resource {
        YQ_RESOURCE_DECLARE(LightSpec, Resource)
    public:

        // TODO (Contents)
    
        LightSpec();
        ~LightSpec();
    
        static void init_meta();
    };
}
