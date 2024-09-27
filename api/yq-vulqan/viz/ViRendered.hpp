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

namespace yq {
    class Stream;
}

namespace yq::tachyon {
    class ViVisualizer;
    struct ViContext;
    class Render3D;
    
    struct ViRenderedOptions {
        VkDescriptorPool        descriptor_pool = nullptr;
        ViPipelineManager*      pipelines       = nullptr;
    };

    struct ViRenderedReportOptions {
        std::string_view        message;
        bool                    layout      = true;
        bool                    pipeline    = true;
    };

    class ViRendered : public ViData, public RefCount {
    public:
    
        ViRendered();
        //ViRendered(const ViRendered&, const ViRenderedOptions& opts={});
        //ViRendered(const ViRendered&, const PipelineCPtr pipe, const ViRenderedOptions& opts={});
        ViRendered(ViVisualizer&, const RenderedCPtr&, const ViRenderedOptions& options={});
        ViRendered(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& options={});
        ~ViRendered();
        
        std::error_code init(ViVisualizer&, const RenderedCPtr&, const ViRenderedOptions& options={});
        std::error_code init(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& options={});
    
        //! Dumps out to the viz debug stream full information to this rendered.
        void    debug_report() const;
    
        void    kill();
        
        //! Updates us
        void    update(ViContext& u);
        
        //! Publishes descriptor changes
        void    descriptors();
        void    record(ViContext&);
        
        RenderedCPtr        rendered() const;
        
        bool    consistent() const;
        bool    valid() const;
    
        ViPipelineCPtr          pipeline() const;
        ViPipelineLayoutCPtr    pipeline_layout() const;
        
        void                report(Stream&, const ViRenderedReportOptions& options={}) const;
    
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
        PushBuffer              m_push;
        Flags<S>                m_status = {};

        std::error_code _init(ViVisualizer&, const RenderedCPtr&, const PipelineCPtr& pipe, const ViRenderedOptions& opts);
        void            _kill();
        void            _update(ViContext&);
        void            _descriptors();
        void            _record(ViContext&);
    };
}
