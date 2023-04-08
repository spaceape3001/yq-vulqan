////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Rendered.hpp>
#include <tachyon/gfx/PipelineBuilder.hpp>
#include <meta/ObjectInfoWriter.hpp>

namespace yq {
    namespace tachyon {
        
        template <typename C>
        class RenderedInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(RenderedInfo* renderInfo) : MetaObjectInfo::Writer<C>(renderInfo), m_meta(renderInfo)
            {
            }
            
            Writer(RenderedInfo& renderInfo) : Writer(&renderInfo)
            {
            }

            void    _2d()
            {
                if(m_meta)
                    m_meta->m_flags |= RenderedBit::D2;
            }
            
            void    _3d()
            {
                if(m_meta)
                    m_meta->m_flags |= RenderedBit::D3;
            }

            void    _4d()
            {
                if(m_meta)
                    m_meta->m_flags |= RenderedBit::D4;
            }
            
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

        private:
            RenderedInfo*       m_meta  = nullptr;
        };
    
    }
}
