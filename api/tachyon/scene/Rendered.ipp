////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Rendered.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Rendered)

namespace yq {
    namespace tachyon {
        RenderedInfo::RenderedInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) : 
            ObjectInfo(name, base, sl)
        {
            set_option(RENDERED);
        }

        PipelineCPtr    RenderedInfo::pipeline(Pipeline::role_t r) const
        {
            auto i = m_pipelines.find(r);
            if(i != m_pipelines.end())
                return i->second;
            return {};
        }

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        Rendered::Rendered()
        {
        }
        
        Rendered::~Rendered()
        {
        }

        PipelineCPtr    Rendered::pipeline() const
        {
            if(m_pipeline)
                return m_pipeline;
            return metaInfo().pipeline();
        }

        void            Rendered::set_wireframe(Tristate v)
        {
            m_wireframe = v;
        }
    }
}
