////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/video.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! \brief Light specification/configuration
    
        This is data from the file, can be used to create actual light sources.
        
        \note Named to not conflict with the tachyon (so that a GLTF won't accidentally instantiate one)
    */
    class Video : public Resource {
        YQ_RESOURCE_DECLARE(Video, Resource)
    public:

        // TODO (Contents)
    
        Video();
        ~Video();
    
        static void init_meta();
    };
}
