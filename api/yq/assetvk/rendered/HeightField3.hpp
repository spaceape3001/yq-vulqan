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
#include <yq/tachyon/aspect/ADrawMode.hpp>
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
    class HeightField³ : public Rendered³, public AColor, public ACount², public ADrawMode, public AHeightField, public AMaterial, public ASize³ {
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
        
        using ADrawMode::draw_mode;
        virtual bool    draw_mode(settable_k) const override { return true; }

        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }

    protected:
        std::error_code     load(const StateSave&) override;
        
    private:
    
        /*
            Permutations in geometry... with & w/o a real height map
            Permutations in color ... material/texture/colorprofile/solid/debug (w & w/o height map)
            Permutations in lighting ... simple, lit, ray
        */
    
     
    
        void    snap(Rendered³Snap&) const;
        void    rebuild();
        
        struct Gridder;
        
        //  Idea is coloration (by altitude) instead of all the same... another draw mode...
        //TextureCPtr     m_color;


        struct UData {
            glm::vec4   oTess       = { 1., 1., 1., 1. };
            glm::vec4   rgba        = { 1., 1., 1., 1. };
            glm::vec2   iTess       = { 1., 1. };
            glm::vec2   uvScale     = { 1., 1. };
            glm::vec2   uvOffset    = { 0., 0. };
            float       cmScale     = 1.;
            float       cmOffset    = 0.;
        };
                
        IB1<uint32_t>       m_index;
        VB1<glm::vec2>      m_vbo;  // UV coordinates....
        UB1<UData>          m_ubo;
        Vector4U            m_oTess = { 1, 1, 1, 1 };
        Vector2U            m_iTess = { 1, 1 };
        
        void        divide(const Vector2U&);
        
        bool good_heightfield() const;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::HeightField³)
