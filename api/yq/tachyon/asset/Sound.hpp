////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/sound.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! \brief Light specification/configuration
    
        This is data from the file, can be used to create actual light sources.
        
        \note Named to not conflict with the tachyon (so that a GLTF won't accidentally instantiate one)
    */
    class Sound : public Resource {
        YQ_RESOURCE_DECLARE(Sound, Resource)
    public:

        // TODO (Contents)
    
        Sound();
        ~Sound();
    
        static void init_meta();
    };
}
