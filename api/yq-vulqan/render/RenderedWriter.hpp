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
        Pipeline::Typed<C>&    pipeline(Pipeline::role_t r={}) 
        {
            assert(Meta::thread_safe_write() && m_meta);
            
            auto [i,f] = m_meta->m_pipelines.insert({r, nullptr});
            if(!f)
                return *static_cast<Pipeline::Typed<C>*>(i->second.ptr());
            
            Pipeline::Typed<C>*  p2 = new Pipeline::Typed<C>(r);
            i->second   = p2;
            return *p2;
        }
        
        //! Returns a reference to the given meta (warning, may seg fault if it's NULL)
        const RenderedInfo& meta() const { return *m_meta; }

    private:
        RenderedInfo*       m_meta  = nullptr;
    };

}
