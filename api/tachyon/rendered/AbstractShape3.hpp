////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Rendered3.hpp>

namespace yq::tachyon {
    struct Vertex³;

    class AbstractShape³ : public Rendered³ {
        YQ_TACHYON_DECLARE(AbstractShape³, Rendered³)
    public:

        struct Param : public Rendered³::Param {
            //RGBA4F      bgcolor     = kDefBgColor;
            //RGBA4F      color       = kDefColor;
        };
        
        static void init_info();

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
