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
            
            class Builder;
            template <typename> class Typed;
            template <typename> class VBOMaker;
            
            /*! \brief Creates a pipeline
            
                \tparam C   type being created for
            */
            template <typename C=void>
            static auto build(std::string_view name=std::string_view());   
            
            const PipelineConfig&       config() const { return m_config; }
            
            Pipeline(const PipelineConfig&);
            Pipeline(PipelineConfig&&);
            
            std::string_view            name() const { return m_config.name; }
            
        private:
            PipelineConfig              m_config;
            ~Pipeline();
        };
    }
}
