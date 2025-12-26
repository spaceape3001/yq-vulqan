////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/pipeline/PipelineWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of information for rendered information
    */
    template <typename C>
    class RenderedMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(RenderedMeta* renderInfo) : TachyonMeta::Writer<C>(renderInfo), m_meta(renderInfo)
        {
        }
        
        Writer(RenderedMeta& renderInfo) : Writer(&renderInfo)
        {
        }
        
        bool    has_pipeline(PipelineKey r) const
        {
            if(m_meta)
                return static_cast<bool>(m_meta->pipeline(r));
            return false;
        }
        
        /*! \brief Creates and returns a new pipeline builder
        
            This creates a new pipeline for the given meta, 
            returning the builder (moved out)
        */
        Pipeline::Typed<C>&    pipeline(PipelineKey r=pipekey::DEFAULT) 
        {
            assert(m_meta);
            return *static_cast<Pipeline::Typed<C>*>(m_meta->create_pipeline(r, create_pipeline));
        }
        
        //! Returns a reference to the given meta (warning, may seg fault if it's NULL)
        const RenderedMeta& meta() const { return *m_meta; }

    private:
        static Pipeline*       create_pipeline(PipelineKey r)
        {
            return new Pipeline::Typed<C>(r);
        }
        
        RenderedMeta*       m_meta  = nullptr;
    };

}
