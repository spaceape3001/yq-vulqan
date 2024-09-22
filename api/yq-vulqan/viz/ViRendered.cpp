////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViRendered.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/render/Rendered.hpp>
#include <yq-vulqan/viz/ViPipeline.hpp>
#include <yq-vulqan/viz/ViPipelineLayout.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using rendered_bad_state        = error_db::entry<"Rendered is in a bad state">;
        using rendered_existing         = error_db::entry<"Rendered has already been created">;
        using rendered_null_pointer     = error_db::entry<"Rendered pointer is null">;
        using rendered_missing_pipeline = error_db::entry<"Rendered missing a valid pipeline">;
        using rendered_null_pipeline    = error_db::entry<"Rendered unable to use null pipeline">;
    }
    
    ViRendered::ViRendered()
    {
    }
    
    ViRendered::ViRendered(ViVisualizer&viz, RenderedCPtr ren, const ViRenderedOptions& opts)
    {
        if(!viz.device())
            return;
        if(!ren)
            return;
        PipelineCPtr    pipe    = ren->pipeline();
        if(!pipe)
            return ;

        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            vizWarning << "ViRendered -- unable to initialize: " << ec.message();
        }
    }
    
    ViRendered::ViRendered(ViVisualizer& viz, RenderedCPtr ren, const PipelineCPtr pipe, const ViRenderedOptions& opts)
    {
        if(!viz.device())
            return;
        if(!ren)
            return;
        if(!pipe)
            return ;

        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            vizWarning << "ViRendered -- unable to initialize: " << ec.message();
        }
    }
    
    ViRendered::~ViRendered()
    {
        kill();
    }
    
    void            ViRendered::_descriptors(ViContext&ctx)
    {
    }
    
    
    std::error_code ViRendered::_init(ViVisualizer& viz, RenderedCPtr ren, const PipelineCPtr pipe, const ViRenderedOptions& opts)
    {
        
        return errors::todo();
    }
    
    void            ViRendered::_kill()
    {
    }
    
    void            ViRendered::_record(ViContext& ctx)
    {
    }

    void            ViRendered::_update(ViContext& ctx)
    {
    }
    
    bool    ViRendered::consistent() const
    {
        return m_viz ? (m_rendered && m_pipeline && m_layout && m_viz->device()) : (!m_rendered && !m_pipeline && !m_layout);
    }

    void    ViRendered::descriptors(ViContext& ctx)
    {
        if(valid())
            _descriptors(ctx);
    }
    
    std::error_code ViRendered::init(ViVisualizer&viz, RenderedCPtr ren, const ViRenderedOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::rendered_bad_state();
            }
            return errors::rendered_existing();
        }
        
        if(!viz.device())
            return errors::visualizer_uninitialized();
        if(!ren)
            return errors::rendered_null_pointer();

        PipelineCPtr    pipe    = ren->pipeline();
        if(!pipe)
            return errors::rendered_missing_pipeline();
        
        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    
    std::error_code ViRendered::init(ViVisualizer&viz, RenderedCPtr ren, const PipelineCPtr pipe, const ViRenderedOptions& opts)
    {
        if(m_viz){
            if(!consistent()){
                return errors::rendered_bad_state();
            }
            return errors::rendered_existing();
        }

        if(!viz.device())
            return errors::visualizer_uninitialized();
        if(!ren)
            return errors::rendered_null_pointer();
        if(!pipe)
            return errors::rendered_null_pipeline();
            
        std::error_code ec  = _init(viz, ren, pipe, opts);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }

    void    ViRendered::kill()
    {
        _kill();
    }
    
    void    ViRendered::record(ViContext& ctx)
    {
        if(valid())
            _record(ctx);
    }
    
    void    ViRendered::update(ViContext& ctx)
    {
        if(valid())
            _update(ctx);
    }
    
    bool    ViRendered::valid() const
    {
        return (m_viz && m_viz->device() && m_rendered);
    }
}
