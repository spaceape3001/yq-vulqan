////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/vector/Vector2.hpp>

#include <tachyon/api/Rendered3.hpp>
#include <tachyon/asset/Texture.hpp>
#include <tachyon/pipeline/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class ImageQuad³ : public Rendered³ {
        YQ_TACHYON_DECLARE(ImageQuad³, Rendered³)
    private:
        struct VData;
    public:
    
        ImageQuad³(const AxBox2D&, std::string_view szImage, const Param& p={});
        ~ImageQuad³();
        
        static void init_meta();
        
    private:

        struct VData {
            glm::vec2   position, uv;
        };
    
        VB1<VData>          m_vertex;
        Ref<const Texture>  m_texture;
    };
}
