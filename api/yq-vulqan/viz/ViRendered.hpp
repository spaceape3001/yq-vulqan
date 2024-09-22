////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/container/BasicBuffer.hpp>
#include <yq-vulqan/viz/ViData.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/pipeline_layout.hpp>
#include <yq-vulqan/typedef/rendered.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    struct ViContext;
    
    struct ViRenderedOptions {
        VkDescriptorPool        descriptor_pool = nullptr;
        ViPipelineManager*      pipelines       = nullptr;
    };

    class ViRendered : public RefCount, public ViData {
    public:
    
        ViRendered();
        //ViRendered(const ViRendered&, const ViRenderedOptions& opts={});
        //ViRendered(const ViRendered&, const PipelineCPtr pipe, const ViRenderedOptions& opts={});
        ViRendered(ViVisualizer&, RenderedCPtr, const ViRenderedOptions& opts={});
        ViRendered(ViVisualizer&, RenderedCPtr, const PipelineCPtr pipe, const ViRenderedOptions& opts={});
        ~ViRendered();
        
        std::error_code init(ViVisualizer&, RenderedCPtr, const ViRenderedOptions& opts={});
        std::error_code init(ViVisualizer&, RenderedCPtr, const PipelineCPtr pipe, const ViRenderedOptions& opts={});
    
        void    kill();
        void    update(ViContext&);
        void    descriptors(ViContext&);
        void    record(ViContext&);
        bool    consistent() const;
        bool    valid() const;
    
    private:
        RenderedCPtr            m_rendered;
        ViPipelineLayoutCPtr    m_layout;
        ViPipelineCPtr          m_pipeline;
        PushBuffer              m_push;

        std::error_code _init(ViVisualizer&, RenderedCPtr, const PipelineCPtr pipe, const ViRenderedOptions& opts);
        void            _kill();
        void            _update(ViContext&);
        void            _descriptors(ViContext&);
        void            _record(ViContext&);
    };
}
