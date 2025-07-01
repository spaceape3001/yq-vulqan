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

    /*! \brief An image "billboard" that'll always face the camera
    */
    class Billboard³ : public Rendered³ {
        YQ_TACHYON_DECLARE(Billboard³, Rendered³)
    private:
        struct VData;
    public:
    
        Billboard³(const AxBox2D&, std::string_view szImage, const Param& p={});
        ~Billboard³();
        
        static void init_meta();
        
    protected:
        void        snap(Rendered³Snap& sn) const;
        
    private:

        struct VData {
            glm::vec2   position, uv;
        };
    
        VB1<VData>          m_vertex;
        Ref<const Texture>  m_texture;
    };
}
