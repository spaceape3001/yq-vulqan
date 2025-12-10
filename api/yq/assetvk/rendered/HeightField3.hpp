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
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>

namespace yq::tachyon {
    class HeightField³ : public Rendered³, public AColor, public AHeightField, public AMaterial {
        YQ_TACHYON_DECLARE(HeightField³, Rendered³)
    public:
        
        HeightField³();
        HeightField³(const Param&);
        virtual ~HeightField³();
    
        static void init_meta();
        Execution tick(const Context&) override;
        
    private:
        void    rebuild();
        
        struct UData {
            glm::vec4   rgba;
        };
        
        IB1<uint32_t>   m_index;
        VB1<glm::vec2>  m_verts;
        UB1<UData>      m_ubo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::HeightField³)
