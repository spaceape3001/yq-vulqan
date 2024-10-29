////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/vector/Vector2.hpp>

#include <tachyon/render/Render3D.hpp>
#include <tachyon/texture/Texture.hpp>
#include <tachyon/pipeline/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class ImageQuad2 : public Render3D {
        YQ_OBJECT_DECLARE(ImageQuad2, Render3D)
    private:
        struct VData;
    public:
    
        ImageQuad2(const AxBox2D&, std::string_view szImage);
        ~ImageQuad2();
        
        static void initInfo();
        
    private:

        struct VData {
            glm::vec2   position, uv;
        };
    
        VB1<VData>          m_vertex;
        Ref<const Texture>  m_texture;
    };
}
