////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/render/Rendered.hpp>
#include <yq-vulqan/pipeline/PipelineWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of information for rendered information
    */
    template <typename C>
    class RenderedInfo::Writer : public MetaObjectInfo::Writer<C> {
    public:
        Writer(RenderedInfo* renderInfo) : MetaObjectInfo::Writer<C>(renderInfo), m_meta(renderInfo)
        {
        }
        
        Writer(RenderedInfo& renderInfo) : Writer(&renderInfo)
        {
        }
        
        
        /*! \brief Creates and returns a new pipeline builder
        
            This creates a new pipeline for the given meta, 
            returning the builder (moved out)
        */
        Pipeline::Typed<C>&    pipeline(Pipeline::Role r=Pipeline::Role::Default) 
        {
            assert(m_meta);
            return *static_cast<Pipeline::Typed<C>*>(m_meta->create_pipeline(r, create_pipeline));
        }
        
        //! Returns a reference to the given meta (warning, may seg fault if it's NULL)
        const RenderedInfo& meta() const { return *m_meta; }

    private:
        static Pipeline*       create_pipeline(Pipeline::Role r)
        {
            return new Pipeline::Typed<C>(r);
        }
        
        RenderedInfo*       m_meta  = nullptr;
    };

}
