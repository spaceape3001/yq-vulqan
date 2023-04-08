////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Flags.hpp>
#include <basic/MetaObject.hpp>
#include <basic/Mutable.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/enum/Tristate.hpp>
#include <tachyon/gfx/Pipeline.hpp>

namespace yq {
    namespace tachyon {
        enum class RenderedBit {
            D2,
            D3, // Its a graphics thing so likely?
            D4  // haven't a clue on doing 4D (spatial) "widgets"
        };
        
        using RenderedFlags = Flags<RenderedBit, uint8_t>; 

        class RenderedInfo : public MetaObjectInfo {
        public:
            template <typename C> struct Writer;
            
            RenderedInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());

            bool            is_2d() const
            {
                return m_flags.is_set(RenderedBit::D2);
            }
        
            bool            is_3d() const
            {
                return m_flags.is_set(RenderedBit::D3);
            }

            bool            is_4d() const
            {
                return m_flags.is_set(RenderedBit::D4);
            }
            
            PipelineCPtr    pipeline(Pipeline::role_t r={}) const;
            
        private:
            using PipelineHash  = std::unordered_map<Pipeline::role_t, PipelineCPtr>;
            PipelineHash    m_pipelines;
            RenderedFlags   m_flags;
        };
        
        class Rendered : public MetaObject {
            YQ_OBJECT_INFO(RenderedInfo)
            YQ_OBJECT_DECLARE(Rendered, MetaObject)
        public:
        
            Rendered();
            ~Rendered();
            
            struct Draw {
                uint32_t    vertex_count     = 0;
                uint32_t    instance_count   = 1;
            };
            
            const Draw&     draw() const { return m_draw; }
            
            //! Wireframe (override), inherit uses scene's setting
            Tristate        wireframe() const { return m_wireframe; }
            bool            culled() const { return m_culled; }
            PipelineCPtr    pipeline() const;

            void            set_wireframe(Tristate);
            
        protected:
            //! Pipeline override
            PipelineCPtr    m_pipeline; 
            
            //! Draw command
            Draw            m_draw; 

            //! Wireframe mode
            Tristate        m_wireframe;
            
            //! Culling flag
            bool            m_culled    = false;
            
        };
        
    }
}
