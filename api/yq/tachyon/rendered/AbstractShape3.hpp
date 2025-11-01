////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/aspect/ADrawMode.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/ABgColor.hpp>

namespace yq::tachyon {
    struct Vertex³;

    class AbstractShape³ : public Rendered³ {
        YQ_TACHYON_DECLARE(AbstractShape³, Rendered³)
    public:

        struct Param : public Rendered³::Param {
            //RGBA4F      bgcolor     = kDefBgColor;
            //RGBA4F      color       = kDefColor;
            //DrawMode    draw_mode   = kDefDrawMode;
        };
        
        static void init_meta();

        Execution           setup(const Context&) override;
        Execution           tick(const Context&) override;

        //using ADrawMode::draw_mode;
        //virtual bool    draw_mode(settable_k) const override { return true; }
        
        //using AColor::color;
        //virtual bool    color(settable_k) const override { return true; }
        
        //using ABgColor::bgcolor;
        //virtual bool    bgcolor(settable_k) const override { return true; }

    protected:
    
        AbstractShape³(const Param&);
        ~AbstractShape³();
    
        struct VertexC {
            glm::vec4   color;
            glm::vec3   position;
        };
        
        struct VertexT {
            glm::vec3   position;
            glm::vec2   uv;
        };
        
        struct VertexCT {
            glm::vec4   color;
            glm::vec3   position;
            glm::vec2   uv;
        };
        
        struct VertexS {
            glm::vec3   position;
        };

        struct UBS {
            glm::vec4   color;
        };

        static VertexC  vc(const Vertex³&);
        static VertexCT vct(const Vertex³&);
        static VertexT  vt(const Vertex³&);
        static VertexS  vs(const Vertex³&);
        
        #if 0
        //  We're going to add variations as necessary, but try to reuse them... 
        
        VB1<VertexC>    m_vertexC;
        VB1<VertexCT>   m_vertexCT;
        VB1<VertexT>    m_vertexT;
        VB1<VertexS>    m_vertexS;
        
        UB1<UBS>        m_uniformS;
        TextureCPtr     m_texture;
        #endif
        
        //template <typename C>
        //requires std::is_base_of<C,AbstractShape³>
        //static void     pipeline_color(

        // Called whenever we've been marked "dirty" and need to rebuild the render buffers
        virtual void    rebuild(){}
    };
}

YQ_TACHYON_FORCE(yq::tachyon::AbstractShape³)
