////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Rendered.hpp"
#include "RenderWriter.hpp"
#include <basic/DelayInit.hpp>
#include <basic/meta/Init.hpp>
#include <atomic>

namespace yq {
    namespace engine {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        Pipeline::Writer::Writer(Pipeline* p) : Meta::Writer(p), PipelineBuilder(&p->m_config), m_pipeline(p)
        {
        }
        
        Pipeline::Writer::Writer(Pipeline&p) : Writer(&p)
        {
        }
        
        Pipeline::Writer::~Writer() = default;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        RenderedInfo::RenderedInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) : 
            MetaObjectInfo(name, base, sl)
        {
            set_option(RENDERED);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Rendered::Rendered()
        {
        }
        
        Rendered::Rendered(const Rendered&) : Rendered()
        {
        }

        Rendered::~Rendered()
        {
        }
        
        const Pipeline*   Rendered::pipeline() const
        {
            if(m_pipeline)
                return m_pipeline;
            return metaInfo().primary();
        }

        void              Rendered::set_wireframe(Tristate v)
        {
            m_wireframe = v;
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        YQ_INVOKE(
            [[maybe_unused]] auto rend   = writer<Rendered>();
        )
    }
}

YQ_OBJECT_IMPLEMENT(yq::engine::Rendered)
