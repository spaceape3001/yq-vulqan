////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/AHeightField.hpp>
#include <yq/tachyon/aspect/AMaterial.hpp>
#include <yq/tachyon/aspect/ASize3.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>

namespace yq::tachyon {

    /*! Height Field (Render)
    
        Converts a height field (resource) into something the visualizer can render.
        
        By default, the dimensions will be [-1,1] on each axis, with the UV being 0,0 on the -1,-1 corner.
    */
    class HeightField³ : public Rendered³, public AColor, public AHeightField, public AMaterial, public ASize³ {
        YQ_TACHYON_DECLARE(HeightField³, Rendered³)
    public:
    
        struct Param : public Rendered³::Param {
        };
        
        HeightField³();
        HeightField³(const Param&);
        virtual ~HeightField³();
    
        static void init_meta();
        Execution tick(const Context&) override;
        
    private:
    
        void    snap(Rendered³Snap&) const;
        void    rebuild();
        
        struct UData {
            glm::vec4   rgba;
        };
        
        struct Vertex {
            glm::vec2   pos;
            glm::vec2   uv;
        };
        
        //  Idea is coloration (by altitude) instead of all the same... another draw mode...
        //TextureCPtr     m_color;
        
        IB1<uint32_t>       m_index;
        VB1<glm::vec2>      m_vboPos;
        UB1<UData>          m_ubo;
        Size2U              m_count = { 11, 11 };
        
        bool good_heightfield() const;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::HeightField³)
