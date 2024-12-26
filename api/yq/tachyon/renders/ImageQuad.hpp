////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yq/tachyon/api/Render³.hpp>
#include <yq/tachyon/api/Texture.hpp>
#include <yq/tachyon/api/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class ImageQuad³ : public Render³ {
        YQ_TACHYON_DECLARE(ImageQuad³, Render³)
    private:
        struct VData;
    public:
    
        ImageQuad³(const AxBox2D&, std::string_view szImage);
        ~ImageQuad³();
        
        static void init_info();
        
    private:

        struct VData {
            glm::vec2   position, uv;
        };
    
        VB1<VData>          m_vertex;
        Ref<const Texture>  m_texture;
    };
}
