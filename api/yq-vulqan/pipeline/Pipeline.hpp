////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/pipeline.hpp>

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/basic/UniqueID.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>

namespace yq::tachyon {
    /*! \brief Pipeline configuration
    
        This is a pipeline configuration.  Once created, can be submitted to the 
        visualizer for a proper VkPipeline.
    */
    class Pipeline : public UniqueID, public RefCount {
    public:
        
        using role_t    = decltype(PipelineConfig::role);
        
        class Builder;
        template <typename> class Typed;
        template <typename> class VBOMaker;
        
        /*! \brief Creates a pipeline
        
            \tparam C   type being created for
        */
        template <typename C=void>
        static auto build(role_t role={});   
        
        const PipelineConfig&       config() const { return m_config; }
        
        Pipeline(const PipelineConfig&);
        Pipeline(PipelineConfig&&);
        
        role_t  role() const { return m_config.role; }
        
    private:
        PipelineConfig              m_config;
        ~Pipeline();
    };
}
