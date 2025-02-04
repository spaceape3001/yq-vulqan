////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/typedef/axbox2.hpp>
#include <yq/vector/Vector2.hpp>

#include <yt/3D/Rendered3.hpp>
#include <yt/gfx/Texture.hpp>
#include <yt/gfx/VBO.hpp>

#include <array>

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class Billboard³ : public Rendered³ {
        YQ_TACHYON_DECLARE(Billboard³, Rendered³)
    private:
        struct VData;
    public:
    
        Billboard³(const AxBox2D&, std::string_view szImage, const Param& p={});
        ~Billboard³();
        
        static void init_info();
        
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
