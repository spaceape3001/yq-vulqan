////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


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
    
    struct ViRenderedSpec {
        using spec_t    = std::variant<std::monostate, RenderedCPtr, const RenderedSnap*>;
        spec_t                  rendered{};
        
        uint64_t                id() const;
        const Pipeline*         pipeline() const;
        bool                    valid() const;
    };
    
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
        ViRendered(ViVisualizer&, const ViRenderedSpec&, const ViRenderedOptions& options={});
        ~ViRendered();
        
        std::error_code init(ViVisualizer&, const ViRenderedSpec&, const ViRenderedOptions& options={});
    
        //! Dumps out to the viz debug stream full information to this rendered.
        void    debug_report() const;
    
        void    kill();
        
        //! Updates us
        // NOTE, expect an extra helper once we get proper lighting support into the scene, maybe
        // some sort of "universal" buffer or simialr
        void    update(ViContext& u, const RenderedSnap&, const void* pb=nullptr);
        void    update(ViContext& u, const void* pb=nullptr);
        
        //! Publishes descriptor changes
        void    descriptors();
//        void    record(ViContext&, const PushBuffer&);
        void    record(ViContext&);
        
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
            Index,
            R3
        };
    
        RenderedCPtr            m_rendered;
        const Rendered³*        m_render3d      = nullptr;
        ViPipelineLayoutCPtr    m_layout;
        ViPipelineCPtr          m_pipeline;
        PushBuffer              m_push;
        Flags<S>                m_status = {};

        std::error_code _init(ViVisualizer&, const ViRenderedSpec&, const ViRenderedOptions& opts);
        void            _kill();
        void            _update(ViContext& u, const RenderedSnap*, const void* pb);
        void            _update(ViContext& u, const void* pb);
        void            _descriptors();
        void            _record(ViContext&);
    };
}
