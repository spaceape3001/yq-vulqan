////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/LogPriority.hpp>
#include <yq/core/Ref.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yv/ViData.hpp>
#include <yt/typedef/rendered.hpp>
#include <yv/typedef/vi_pipeline.hpp>
#include <yv/typedef/vi_pipeline_manager.hpp>
#include <yv/typedef/vi_pipeline_layout.hpp>
#include <yv/typedef/vi_rendered.hpp>

namespace yq {
    class Stream;
}

namespace yq::tachyon {
    class ViVisualizer;
    struct ViContext;
    class Rendered³;
    
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
        ViRendered(ViVisualizer&, const RenderedSnap*, const ViRenderedOptions& options={});
        ~ViRendered();
        
        std::error_code init(ViVisualizer&, const RenderedSnap&, const ViRenderedOptions& options={});
    
        //! Dumps out to the viz debug stream full information to this rendered.
        void    debug_report() const;
    
        void    kill();
        
        //! Updates us
        // NOTE, expect an extra helper once we get proper lighting support into the scene, maybe
        // some sort of "universal" buffer or simialr
        void    update(ViContext& u, const RenderedSnap&);
        
        //! Publishes descriptor changes
        void    descriptors();
        void    record(ViContext&, const PushBuffer&, Pipeline::Variation v=Pipeline::Variation::Default) const;
        
        bool    consistent() const;
        bool    valid() const;
    
        ViPipelineCPtr          pipeline() const;
        ViPipelineLayoutCPtr    pipeline_layout() const;
        
        void                report(Stream&, const ViRenderedReportOptions& options={}) const;
        void                report(const char* cat="viz", LogPriority pri=LogPriority::Info, const ViRenderedReportOptions& options={}) const;
    
        uint64_t    id() const { return m_id; }
        
    private:
        enum class S : uint8_t {
            Descriptors,
            Push,
            Vertex,
            Index,
            R3,
            Wireframe
        };
    
        uint64_t                m_id;
        ViPipelineLayoutCPtr    m_layout;
        ViPipelineCPtr          m_pipeline;
        Flags<S>                m_status = {};

        std::error_code _init(ViVisualizer&, const RenderedSnap&, const ViRenderedOptions& opts);
        void            _kill();
        void            _update(ViContext& u, const RenderedSnap&);
        void            _descriptors();
        void            _record(ViContext&, const PushBuffer&, Pipeline::Variation) const;
    };
}
