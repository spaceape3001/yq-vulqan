////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/rendered.hpp>

#include <yq/keywords.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/MetaObject.hpp>
#include <yq/core/Mutable.hpp>
#include <yq/core/Tristate.hpp>
//#include <yq/tachyon/preamble.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>

namespace yq::tachyon {

    //! Information to a rendered object
    class RenderedInfo : public MetaObjectInfo {
    public:
        template <typename C> struct Writer;
        
        //! Standard constructor
        RenderedInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
        
        const Pipeline* pipeline(Pipeline::Role r=Pipeline::Role::Default) const;
        
        //! Default is the FIRST pipeline defined
        const Pipeline* default_pipeline() const { return m_default; }
        
    private:
        using PipelineHash  = std::unordered_map<Pipeline::Role, Pipeline*>;
        PipelineHash    m_pipelines;
        const Pipeline* m_default   = nullptr;
        
        Pipeline*       create_pipeline(Pipeline::Role, std::function<Pipeline*(Pipeline::Role)>);
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
        const Pipeline* pipeline() const;

        //! Sets the wireframe mode
        void            set_wireframe(Tristate);
        
        void            set_pipeline(clear_t);
        void            set_pipeline(nullptr_t);
        void            set_pipeline(Pipeline::Role);
        
        //! Returns the role of the current pipeline
        Pipeline::Role  role() const;
        
        static void init_info();
        
    protected:
        //! Pipeline override
        const Pipeline* m_pipeline = nullptr;
        
        //! Draw command
        Draw            m_draw; 

        //! Wireframe mode
        Tristate        m_wireframe;
        
        //! Culling flag
        bool            m_culled    = false;
        
    };
    
}
