////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Flags.hpp>
#include <0/basic/MetaObject.hpp>
#include <0/basic/Mutable.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/enum/Tristate.hpp>
#include <tachyon/viz/Pipeline.hpp>

namespace yq {
    namespace tachyon {

        //! Information to a rendered object
        class RenderedInfo : public MetaObjectInfo {
        public:
            template <typename C> struct Writer;
            
            //! Standard constructor
            RenderedInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
            
            PipelineCPtr    pipeline(Pipeline::role_t r={}) const;
            
        private:
            using PipelineHash  = std::unordered_map<Pipeline::role_t, PipelineCPtr>;
            PipelineHash    m_pipelines;
        };
        
        /*! \brief Base object that's rendered
        
            A rendered object is one that'll be rendered in the visualizer.  
            It'll have a pipeline (or more), with light extra information
        */
        class Rendered : public MetaObject {
            YQ_OBJECT_INFO(RenderedInfo)
            YQ_OBJECT_DECLARE(Rendered, MetaObject)
        public:
        
            Rendered();
            ~Rendered();
            
            //! Helper for draw counts
            struct Draw {
                uint32_t    vertex_count     = 0;
                uint32_t    instance_count   = 1;
            };
            
            //! Gets the current draw commands
            const Draw&     draw() const { return m_draw; }
            
            //! Wireframe (override), inherit uses scene's setting
            Tristate        wireframe() const { return m_wireframe; }
            
            //! TRUE if this object is culled (ie not rendered)
            bool            culled() const { return m_culled; }
            
            //! Current pipeline
            PipelineCPtr    pipeline() const;

            //! Sets the wireframe mode
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
