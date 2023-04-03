////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Ref.hpp>
#include <basic/UniqueID.hpp>

namespace yq {
    namespace tachyon {
        /*! \brief Pipeline configuration
        
            This is a pipeline configuration.  Once created, can be submitted to the 
            visualizer for a proper VkPipeline.
        */
        class Pipeline : public UniqueID, public RefCount {
        public:
        };
    }
}
