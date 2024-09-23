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
    class Render3D;
    
    struct ViRenderedOptions {
        VkDescriptorPool        descriptor_pool = nullptr;
        ViPipelineManager*      pipelines       = nullptr;
    };

    class ViRendered : public ViData, public RefCount {
    public:
    
        ViRendered();
        //ViRendered(const ViRendered&, const ViRenderedOptions& opts={});
        //ViRendered(const ViRendered&, const PipelineCPtr pipe, const ViRenderedOptions& opts={});
        ViRendered(ViVisualizer&, const RenderedCPtr&, const ViRenderedOptions& opts={});
        ViRendered(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& opts={});
        ~ViRendered();
        
        std::error_code init(ViVisualizer&, const RenderedCPtr&, const ViRenderedOptions& opts={});
        std::error_code init(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& opts={});
    
        void    kill();
        
        //! Updates us
        void    update(ViContext& u);
        
        //! Publishes descriptor changes
        void    descriptors();
        void    record(ViContext&);
        
        bool    consistent() const;
        bool    valid() const;
    
    private:
        enum class S : uint8_t {
            Descriptors,
            Push,
            FullPush,
            ViewPush,
            CustomPush,
            Vertex,
            Index
        };
    
        RenderedCPtr            m_rendered;
        const Render3D*         m_render3d      = nullptr;
        ViPipelineLayoutCPtr    m_layout;
        ViPipelineCPtr          m_pipeline;
        PipelineCPtr            m_pipeline0;
        PushBuffer              m_push;
        Flags<S>                m_status = {};

        std::error_code _init(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& opts);
        void            _kill();
        void            _update(ViContext&);
        void            _descriptors();
        void            _record(ViContext&);
    };
}
