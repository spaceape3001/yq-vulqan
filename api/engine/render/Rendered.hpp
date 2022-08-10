////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>
#include <basic/Revision.hpp>
#include <engine/preamble.hpp>
#include <engine/render/PipelineConfig.hpp>

namespace yq {
    namespace engine {
        class Rendered;
        class Pipeline;
        
        struct RenderDraw {
            uint32_t    vertex_count     = 0;
            uint32_t    instance_count   = 1;
        };

        
        class RenderedInfo : public MetaObjectInfo {
        public:
            template <typename C> struct Writer;

            RenderedInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
            const std::vector<const Pipeline*>&    pipelines() const { return m_pipelines; }
            const Pipeline*     pipeline(std::string_view) const;
            
            //! Primary pipeline (aka first created)
            const Pipeline*     primary() const { return m_primary; }
            
        private:
            const Pipeline*                 m_primary   = nullptr;
            std::vector<const Pipeline*>    m_pipelines;        // all of them
        };


        /*! \brief Shows up on the screen
        
            If you want it to show up on the viewport, it needs to be renderable, and thus derived
            from this thing.
        */
        class Rendered : public MetaObject {
            YQ_OBJECT_INFO(RenderedInfo);
            YQ_OBJECT_DECLARE(Rendered, MetaObject)
        public:    

            const Pipeline*   pipeline() const;
            bool                is_culled() const { return m_culled; }
            
            Tristate            wireframe() const { return m_wireframe; }
            void                set_wireframe(Tristate);
            
            RenderDraw          draw() const { return m_draw; }

        protected:
            Rendered();
            Rendered(const Rendered&);
            ~Rendered();
            
            // NULL defaults to primary pipeline
            const Pipeline*     m_pipeline      = nullptr;
            
            Tristate        m_wireframe;
            bool            m_culled    = false;
            RenderDraw      m_draw;
        };

        using RenderedPtr   = Ref<Rendered>;

    }
}
