////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/ACount2.hpp>
#include <yq/tachyon/aspect/AHeightField.hpp>
#include <yq/tachyon/aspect/AMaterial.hpp>
#include <yq/tachyon/aspect/ASize3.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    /*! Height Field (Render)
    
        Converts a height field (resource) into something the visualizer can render.
        
        By default, the dimensions will be [-1,1] on each axis, with the UV being 0,0 on the -1,-1 corner.
    */
    class HeightField³ : public Rendered³, public AColor, public ACount², public AHeightField, public AMaterial, public ASize³ {
        YQ_TACHYON_DECLARE(HeightField³, Rendered³)
    public:
    
        struct Param : public Rendered³::Param {
            Vector2U    count   = { 20, 20 };
        };
        
        HeightField³();
        HeightField³(const Param&);
        virtual ~HeightField³();
    
        static void init_meta();
        Execution tick(const Context&) override;
        
    protected:
        std::error_code     load(const StateSave&) override;
        
    private:
    
        /*
            Permutations in geometry... with & w/o a real height map
            Permutations in color ... material/texture/colorprofile/solid/debug (w & w/o height map)
            Permutations in lighting ... simple, lit, ray
        */
    
        enum {
            kRoleUser           = (Pipeline::role_t) Pipeline::Role::User,

            kRoleDbgBlackHM,
            kRoleDbgRedHM,
            kRoleDbgOrangeHM,
            kRoleDbgYellowHM,
            kRoleDbgGreenHM,
            kRoleDbgCyanHM,
            kRoleDbgBlueHM,
            kRoleDbgMagentaHM,
            kRoleDbgGrayHM,
            kRoleDbgWhiteHM,

            kRoleSolid,   
            kRoleSolidLit,
            kRoleSolidRay,

            kRoleSolidHM,
            kRoleSolidHMLit,
            kRoleSolidHMRay,

            kRoleProfile,
            kRoleProfileLit,
            kRoleProfileRay,

            kRoleProfileHM,
            kRoleProfileHMLit,
            kRoleProfileHMRay,
            
            kRoleTexture,
            kRoleTextureLit,
            kRoleTextureRay,
            
            kRoleTextureHM,
            kRoleTextureHMLit,
            kRoleTextureHMRay,
            
            kRoleMaterialHM,
            kRoleMaterialHMLit,
            kRoleMaterialHMRay
        };
    
    
        void    snap(Rendered³Snap&) const;
        void    rebuild();
        
        struct UData {
            glm::vec4   itess;
            glm::vec2   otess;
            glm::vec2   vscale  = { 0., 1. };
        };
        
        struct Vertex {
            glm::vec2   pos;
            glm::vec2   uv;
        };
        
        struct Gridder;
        
        //  Idea is coloration (by altitude) instead of all the same... another draw mode...
        //TextureCPtr     m_color;
        
        IB1<uint32_t>       m_index;
        VB1<glm::vec2>      m_vboPos;
        UB1<UData>          m_ubo;
        Vector4U            m_iTess = { 1, 1, 1, 1 };
        Vector2U            m_oTess = { 1, 1 };
        Vector2F            m_vScale = { 0., 1. };
        
        void        divide(const Vector2U&);
        
        bool good_heightfield() const;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::HeightField³)
