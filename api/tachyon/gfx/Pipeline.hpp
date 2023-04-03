////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Ref.hpp>
#include <basic/UniqueID.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>

namespace yq {
    namespace tachyon {
        /*! \brief Pipeline configuration
        
            This is a pipeline configuration.  Once created, can be submitted to the 
            visualizer for a proper VkPipeline.
        */
        class Pipeline : public UniqueID, public RefCount {
        public:
        
            const PipelineConfig&   config() const { return m_config; }
            
            Pipeline(const PipelineConfig&);
            Pipeline(PipelineConfig&&);
            
        protected:
            Pipeline();
            virtual ~Pipeline();
        
        private:
            PipelineConfig      m_config;
        };
    }
}
