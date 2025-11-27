////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/camera_spec.hpp>
#include <yq/resource/Resource.hpp>

namespace yq::tachyon {

    /*! \brief Camera specification
    
        \note Given the duplication to the name, the API takes precedence, and this
        will be camera specifications (from a file).  (CameraConfig could also be used)
    */
    class CameraSpec : public Resource {
        YQ_RESOURCE_DECLARE(CameraSpec, Resource)
    public:
    
        /*
            Thought is to call these "builders" with specialties for cameras, lights, etc.
        */
    
    
        // TODO (Contents)

        CameraSpec();
        ~CameraSpec();
        
        static void init_meta();
    };
    
    
    
}
