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
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/gfx/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A skybox
    
    */
    class SkyBox³ : public Rendered³ {
        YQ_TACHYON_DECLARE(SkyBox³, Rendered³)
    private:
        struct VData;
    public:
    
        //SkyBox³(std::string_view szImage, const Param& p={});
        
        /*! \brief Constructs a skybox from images
        
            Note... six images is required... less than that, and the final image wil
            be used to fill out the rest.  ORDER is +/- X, +/- Y, +/- Z
        */
        SkyBox³(std::initializer_list<std::string_view> szImages, const Param& p={});
        ~SkyBox³();
        
        static void init_info();
        
    private:

        static VB1<glm::vec3>       s_vertex;
        static IB1<uint16_t>        s_index;
        Ref<const Texture>          m_texture;
    };
}
