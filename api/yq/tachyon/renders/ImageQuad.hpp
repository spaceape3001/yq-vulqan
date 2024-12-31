////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Texture.hpp>
#include <yq/tachyon/api/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class ImageQuad3 : public Rendered3 {
        YQ_TACHYON_DECLARE(ImageQuad3, Rendered3)
    private:
        struct VData;
    public:
    
        ImageQuad3(const AxBox2D&, std::string_view szImage, const Param& p={});
        ~ImageQuad3();
        
        static void init_info();
        
    private:

        struct VData {
            glm::vec2   position, uv;
        };
    
        VB1<VData>          m_vertex;
        Ref<const Texture>  m_texture;
    };
}
