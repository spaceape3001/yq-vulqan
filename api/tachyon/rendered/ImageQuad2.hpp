////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Render3D.hpp>
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/pipeline/VBO.hpp>
#include <yq-toolbox/typedef/axbox2.hpp>
#include <yq-toolbox/vector/Vector2.hpp>
#include <glm/glm.hpp>
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
