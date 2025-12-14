////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/rendered.hpp>

#include <yq/keywords.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/container/EnumMap.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>

// ⁴

namespace yq::tachyon {

    class SetWireframeCommand;
    struct IndexDrawCall;
    struct VertexDrawCall;

    //! Information to a rendered object
    class RenderedMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;
        
        //! Standard constructor
        RenderedMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
        
        const Pipeline* pipeline(Pipeline::Role r=Pipeline::Role::Default) const;
        
        //! Default is the FIRST pipeline defined
        const Pipeline* default_pipeline() const { return m_default; }
        
        static const std::vector<const RenderedMeta*>& all();
        
        bool    has_pipeline(Pipeline::Role) const;
        
    private:
        struct Repo;
        static Repo& repo();
    
        using PipelineHash  = std::unordered_map<Pipeline::Role, Pipeline*>;
        PipelineHash    m_pipelines;
        const Pipeline* m_default   = nullptr;
        
        Pipeline*       create_pipeline(Pipeline::Role, std::function<Pipeline*(Pipeline::Role)>);
    };
    
    /*! \brief Base object that's rendered
    
        A rendered object is an object, like a box, that's rendered in 
        the visualizer.  It'll generally be owned by a scene, and will 
        have a pipeline with extra information (keep this frugal!)
        
        If a model needs to show itself via a rendered object, it'll be
        considered the "puppet master" and will push commands to that
        rendered (or puppet its spatial... that's an option too).
    */
    class Rendered : public Tachyon {
        YQ_TACHYON_META(RenderedMeta)
        YQ_TACHYON_DATA(RenderedData)
        YQ_TACHYON_SNAP(RenderedSnap)
        YQ_TACHYON_DECLARE(Rendered, Tachyon)
    public:
    
        /*
            Render Mode... is for simple/lighted/ray-tracing (with full lighting)
            
            ALL pipelines should be otherwise identical in data layout!
            
            WARNING... the LIGHT pipeline will be used for data extraction; if it's not in light,
            it's not going to get covered.
        */
    
        
        //! Helper for draw counts
        //struct Draw {
            //uint32_t    vertex_count     = 0;
            //uint32_t    instance_count   = 1;
        //};
        
        //! Gets the current draw commands
        //const Draw&     draw() const { return m_draw; }
        
        //! Wireframe (override), inherit uses scene's setting
        Tristate        wireframe() const { return m_wireframe; }
        
        //! TRUE if this object is culled (ie not rendered)
        Tristate        culled() const { return m_culled; }
        
        //! Current pipeline for given render mode
        const Pipeline* pipeline(RenderMode rm=RenderMode::Simple) const;

        void            set_culled(Tristate);

        //! Sets the wireframe mode
        void            set_wireframe(Tristate);
        
        void            set_pipeline(clear_k);
        void            set_pipeline(nullptr_t);
        void            set_pipeline(Pipeline::Role);

        void            set_pipeline(RenderMode, clear_k);
        void            set_pipeline(RenderMode, nullptr_t);
        void            set_pipeline(RenderMode, Pipeline::Role);
        
        //! Returns the role of the current pipeline
        Pipeline::Role  role(RenderMode rm=RenderMode::Simple) const;
        
        static void init_meta();
        
        RenderedID      id() const { return RenderedID(UniqueID::id()); }

        //! Generic "rebuild" the vertex, index, buffers (and the like)
        virtual void    rebuild(){}
        
        bool            good() const { return m_good; }
        
        //! If "template", means it's not actually rendered...??? (it's VBOs/UBOs update though)  TBD
        //  Goal here... define a rock that's *NOT* rendered, and make 50k copies of it at various
        //  locations.  Instancing will likely apply.
        bool            is_template() const { return m_template; }

    protected:

        Rendered(const Param&p);
        virtual ~Rendered();

        void snap(RenderedSnap&) const;

        //! Pipeline override
        //const Pipeline* m_pipeline = nullptr;
        
        
        EnumMap<RenderMode,const Pipeline*> m_pipelines;
        
        //! Draw command
        //Draw            m_draw; 

        //! Wireframe mode
        Tristate        m_wireframe = Tristate::INHERIT;
        
        //! Culling flag (UNIVERSAL)
        Tristate        m_culled    = Tristate::INHERIT;
        
        bool            m_good      = true;
        bool            m_template  = false;
        
        //! If empty, old behavior of all index is used when IBO defined.
        std::vector<IndexDrawCall>  m_indexDraws;

        //! If empty, old behavior of all vertex is used when VBO defined.
        std::vector<VertexDrawCall> m_vertexDraws;
        
        
    private:
        void    on_set_wireframe_command(const SetWireframeCommand&);
    };
    
}
YQ_TYPE_DECLARE(yq::tachyon::RenderedID)
