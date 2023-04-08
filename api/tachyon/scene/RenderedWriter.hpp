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
        class RenderedInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer(RenderedInfo* renderInfo) : ObjectInfo::Writer<C>(renderInfo), RenderedInfo(renderInfo)
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
                    if(m_meta){
                        m_meta->m_pipelines[p->role()] = p;
                    }
                });
                return b;
            }

        private:
            RenderedInfo*       m_meta  = nullptr;
        };
    
    }
}
