////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Rendered3.hpp>
#include <tachyon/aspect/ABgColor.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/aspect/ADrawMode.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/typedef/texture.hpp>

namespace yq::tachyon {
    struct Vertex³;

    class AbstractShape³ : public Rendered³, public ABgColor, public AColor, public ADrawMode {
        YQ_TACHYON_DECLARE(AbstractShape³, Rendered³)
    public:

        struct Param : public Rendered³::Param {
            RGBA4F      bgcolor     = kDefBgColor;
            RGBA4F      color       = kDefColor;
            DrawMode    draw_mode   = DrawMode::Auto;
        };
        
        static void init_info();

        using ABgColor::bgcolor;
        virtual bool    bgcolor(settable_k) const { return true; }
    
        using AColor::color;
        virtual bool    color(settable_k) const { return true; }

        using ADrawMode::draw_mode;
        virtual bool        draw_mode(settable_k) const { return true; }
        virtual DrawMode    draw_mode(use_k) const { return draw_mode(); }
    
        Execution           setup(const Context&) override;
        Execution           tick(const Context&) override;

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
        
        //  We're going to add variations as necessary, but try to reuse them... 
        
        VB1<VertexC>    m_vertexC;
        VB1<VertexCT>   m_vertexCT;
        VB1<VertexT>    m_vertexT;
        VB1<VertexS>    m_vertexS;
        
        UB1<UBS>        m_uniformS;
        TextureCPtr     m_texture;
        
        static auto _vertexC() { return &AbstractShape³::m_vertexC; }
        static auto _vertexCT() { return &AbstractShape³::m_vertexCT; }
        static auto _vertexT() { return &AbstractShape³::m_vertexT; }
        static auto _vertexS() { return &AbstractShape³::m_vertexS; }
        static auto _uniformS() { return &AbstractShape³::m_uniformS; }
        static auto _texture()  { return &AbstractShape³::m_texture; }
        
        //template <typename C>
        //requires std::is_base_of<C,AbstractShape³>
        //static void     pipeline_color(

        // Called whenever we've been marked "dirty" and need to rebuild the render buffers
        virtual void    rebuild(){}
    };
}
