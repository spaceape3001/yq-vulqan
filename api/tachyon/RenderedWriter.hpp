////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Rendered.hpp>
#include <tachyon/PipelineBuilder.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

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
        auto    pipeline(Pipeline::role_t r={}) 
        {
            auto    b   = Pipeline::build<C>(r);
            b.set_auto_gen([m=m_meta](PipelineCPtr p){
                if(m){
                    m->m_pipelines[p->role()] = p;
                }
            });
            return b;
        }
        
        //! Returns a reference to the given meta (warning, may seg fault if it's NULL)
        const RenderedInfo& meta() const { return *m_meta; }

    private:
        RenderedInfo*       m_meta  = nullptr;
    };

}
