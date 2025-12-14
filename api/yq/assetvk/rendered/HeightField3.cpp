////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HeightField3.hpp"

#include <yq/core/IntRange.hpp>
#include <yq/math/UV.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Math.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/pipeline/DrawCall.hpp>

#include <yq/shape/AxBox2.hxx>
#include <yq/tachyon/aspect/AColorWriter.hxx>
#include <yq/tachyon/aspect/ACount2Writer.hxx>
#include <yq/tachyon/aspect/ADrawModeWriter.hxx>
#include <yq/tachyon/aspect/AHeightFieldWriter.hxx>
#include <yq/tachyon/aspect/AMaterialWriter.hxx>
#include <yq/tachyon/aspect/ASize3Writer.hxx>
#include <yq/vector/Vector4.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HeightField³)



namespace yq::tachyon {
    namespace {
        static constexpr const uint32_t kT_heightMap        = 2;
        static constexpr const uint32_t kU_heightUniform    = 2;
        

        //enum {
            //kRoleUser           = (Pipeline::role_t) Pipeline::Role::User,

            //kRoleDbgBlackHM,
            //kRoleDbgRedHM,
            //kRoleDbgOrangeHM,
            //kRoleDbgYellowHM,
            //kRoleDbgGreenHM,
            //kRoleDbgCyanHM,
            //kRoleDbgBlueHM,
            //kRoleDbgMagentaHM,
            //kRoleDbgGrayHM,
            //kRoleDbgWhiteHM,

            //kRoleSolid,   
            //kRoleSolidLit,
            //kRoleSolidRay,

            //kRoleSolidHM,
            //kRoleSolidHMLit,
            //kRoleSolidHMRay,

            //kRoleProfile,
            //kRoleProfileLit,
            //kRoleProfileRay,

            //kRoleProfileHM,
            //kRoleProfileHMLit,
            //kRoleProfileHMRay,
            
            //kRoleTexture,
            //kRoleTextureLit,
            //kRoleTextureRay,
            
            //kRoleTextureHM,
            //kRoleTextureHMLit,
            //kRoleTextureHMRay,
            
            //kRoleMaterialHM,
            //kRoleMaterialHMLit,
            //kRoleMaterialHMRay
        //};
            
        static constexpr const Pipeline::Role   kDbgBlack       = Pipeline::Role::DbgBlack;
        static constexpr const Pipeline::Role   kDbgRed         = Pipeline::Role::DbgRed;
        static constexpr const Pipeline::Role   kDbgOrange      = Pipeline::Role::DbgOrange;
        static constexpr const Pipeline::Role   kDbgYellow      = Pipeline::Role::DbgYellow;
        static constexpr const Pipeline::Role   kDbgGreen       = Pipeline::Role::DbgGreen;
        static constexpr const Pipeline::Role   kDbgCyan        = Pipeline::Role::DbgCyan;
        static constexpr const Pipeline::Role   kDbgBlue        = Pipeline::Role::DbgBlue;
        static constexpr const Pipeline::Role   kDbgMagenta     = Pipeline::Role::DbgMagenta;
        static constexpr const Pipeline::Role   kDbgGray        = Pipeline::Role::DbgGray;
        static constexpr const Pipeline::Role   kDbgWhite       = Pipeline::Role::DbgWhite;
        
        static constexpr const Pipeline::Role   kDbgBlackHM     = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgRedHM       = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgOrangeHM    = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgYellowHM    = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgGreenHM     = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgCyanHM      = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgBlueHM      = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgMagentaHM   = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgGrayHM      = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kDbgWhiteHM     = YQ_PIPELINE_ROLE;
        
        static constexpr const Pipeline::Role   kSimple         = YQ_PIPELINE_ROLE;
        static constexpr const Pipeline::Role   kSimpleHM       = YQ_PIPELINE_ROLE;

    }


    void HeightField³::init_meta()
    {
        auto w = writer<HeightField³>();
        w.description("Height Field Render Object");
        AColor::init_meta(w);
        ACount²::init_meta(w);
        ADrawMode::init_meta(w);
        AHeightField::init_meta(w);
        AMaterial::init_meta(w);
        ASize³::init_meta(w);
        
        {
            auto& p = w.pipeline();
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/cyan.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgBlack);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/black.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgBlackHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/black.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgRed);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/red.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgRedHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/red.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgOrange);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/orange.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgOrangeHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/orange.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgYellow);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/yellow.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgYellowHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/yellow.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgGreen);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/green.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgGreenHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/green.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }


        {
            auto& p = w.pipeline(kDbgCyan);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/cyan.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }


        {
            auto& p = w.pipeline(kDbgCyanHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/cyan.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgMagenta);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/magenta.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgMagentaHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/magenta.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgGray);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/gray.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgGrayHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/gray.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgWhite);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/debug/color/white.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kDbgWhiteHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/debug/color/white.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }

        {
            auto& p = w.pipeline(kSimple);
            p.shader( "yq/heightfield3/simple.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/simple.tese" );
            p.shader( "yq/heightfield3/simple.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Fill);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.push_full();
            p.patch_control_points(4);
        }


        {
            auto& p = w.pipeline(kSimpleHM);
            p.shader( "yq/heightfield3/heightmap.vert" );
            p.shader( "yq/heightfield3/simple.tesc" );
            p.shader( "yq/heightfield3/heightmap.tese" );
            p.shader( "yq/heightfield3/simple.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vbo, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Fill);
            p.uniform(&HeightField³::m_ubo, {.activity=DYNAMIC, .binding = kU_heightUniform});
            p.texture(&AHeightField::m_heightField, {.activity=DYNAMIC, .binding = kT_heightMap});
            p.push_full();
            p.patch_control_points(4);
        }


#if 0
        {
            auto& p = w.pipeline();
            p.shader( "asset/heightfield3/default.vert" );
            p.shader( "asset/heightfield3/default.tesc" );
            p.shader( "asset/heightfield3/default.tese" );
            p.shader( "debug/color/cyan.frag" );
            p.topology(Topology::PatchList);
            p.vertex(&HeightField³::m_vboPos, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
            p.push_full();
            p.patch_control_points(4);
        }
#endif
    }

    HeightField³::HeightField³() : HeightField³(Param())
    {
    }
    
    HeightField³::HeightField³(const Param& p) : Rendered³(Param()), ACount²(p.count)
    {
    }
    
    HeightField³::~HeightField³()
    {
    }
    
    struct HeightField³::Gridder {
    // most likely... remove the box, and move this to the toolbox... (along with a row/col major setting)
        AxBox2D     m_box;
        Vector2U    m_count;
    
        Gridder(const Vector2U& cnt, const AxBox2D& box) : m_box(box), m_count(cnt)
        {
        }
        
        double  frac(x_k, unsigned i) const
        {
            return i / (double) m_count.x;
        }
        
        double  frac(y_k, unsigned j) const
        {
            return j / (double) m_count.y;
        }
        
        Vector2D frac(unsigned i, unsigned j) const
        {
            return { frac(X,i), frac(Y,j) };
        }

        glm::dvec2    uv(unsigned i, unsigned j) const
        {
            return { frac(X,i), frac(Y,j) };
        }
        
        glm::dvec2 pos(unsigned i, unsigned j) const
        {
            return m_box.project(frac(i,j));
        }
        
        size_t  post(unsigned i, unsigned j) const
        {
            return i + (m_count.x+1) * j;
        }
        
        size_t  posts(count_k) const
        {
            return (m_count.x+1)*(m_count.y+1);
        }
        
        IntRange<unsigned>    xext() const
        {
            return int_range(0U, m_count.x+1);
        }
        
        IntRange<unsigned>    xint() const
        {
            return int_range(0U, m_count.x);
        }
        
        IntRange<unsigned>    yext() const
        {
            return int_range(0U, m_count.y+1);
        }
        
        IntRange<unsigned>    yint() const
        {
            return int_range(0U, m_count.y);
        }
        
    };

    void HeightField³::divide(const Vector2U& cnt)
    {
        if(!(cnt.x && cnt.y))
            return;
            
        static constexpr const AxBox2D  kStdBox = AxBox2D( -Vector2D(ONE), Vector2D(ONE));

        Gridder grid(cnt, kStdBox);
        
        m_vbo.data.resize(grid.posts(COUNT));
        for(unsigned j : grid.yext())
            for(unsigned i : grid.xext())
        {
            m_vbo.data[grid.post(i,j)] = grid.uv(i,j);
        }
        m_vbo.update();
        
        m_index.data.clear();
        for(unsigned i : grid.xint())
            for(unsigned j : grid.yint())
        {
            m_index.data.push_back( grid.post(i,j  ));
            m_index.data.push_back( grid.post(i,j+1));
            m_index.data.push_back( grid.post(i+1,j));
            m_index.data.push_back( grid.post(i+1,j+1));
        }
        m_index.update();
    }

    bool HeightField³::good_heightfield() const
    {
        if(!m_heightField)
            return false;
        if(m_heightField->images.size() != 1)
            return false;
        if(!m_heightField->images[0])
            return false;
        return true;
    }
    
    std::error_code     HeightField³::load(const StateSave&ss) 
    {
        std::error_code ec  = Rendered³::load(ss);
        rebuild();
        return ec;
    }

    void    HeightField³::rebuild()
    {
        // alter so a bad height field is... still there, just a no-heightmap shader... 
        // Have the AHeightField ... detect for Raster ... smart sampler
        // Resource might need multiple meta for verification
        //if(!good_heightfield()){
            //m_good = false;
            //return ;
        //}
        
        auto& cnt   = ACount²::m_count;
        m_good    = cnt.x && cnt.y;
        if(!m_good)
            return ;
            
        divide(ACount²::m_count);
        
        m_ubo.data.oTess = m_oTess.cast<float>();
        m_ubo.data.iTess = m_iTess.cast<float>();

        tachyonInfo << "HeightField³::rebuild() ... height field? " << (m_heightField ? "yes" : "no");

        switch(m_drawMode){
        case DrawMode::Auto:
            set_pipeline(kDbgCyan);
            break;
            
        case DrawMode::Color:
            m_ubo.data.rgba  = m_color;
            if(m_heightField){
                set_pipeline(kSimpleHM);
            } else
                set_pipeline(kSimple);
            break;
        case DrawMode::DbgBlack:
            if(m_heightField){
                set_pipeline(kDbgBlackHM);
            } else
                set_pipeline(kDbgBlack);
            break;
        case DrawMode::DbgRed:
            if(m_heightField){
                set_pipeline(kDbgRedHM);
            } else
                set_pipeline(kDbgRed);
            break;
        case DrawMode::DbgOrange:
            if(m_heightField){
                set_pipeline(kDbgRedHM);
            } else
                set_pipeline(kDbgOrange);
            break;
        case DrawMode::DbgYellow:
            if(m_heightField){
                set_pipeline(kDbgYellowHM);
            } else
                set_pipeline(kDbgYellow);
            break;
        case DrawMode::DbgGreen:
            if(m_heightField){
                set_pipeline(kDbgGreenHM);
            } else
                set_pipeline(kDbgGreen);
            break;
        default:
        case DrawMode::DbgCyan:
            if(m_heightField){
                set_pipeline(kDbgCyanHM);
            } else
                set_pipeline(kDbgCyan);
            break;
        case DrawMode::DbgBlue:
            if(m_heightField){
                set_pipeline(kDbgBlueHM);
            } else
                set_pipeline(kDbgBlue);
            break;
        case DrawMode::DbgMagenta:
            if(m_heightField){
                set_pipeline(kDbgMagentaHM);
            } else
                set_pipeline(kDbgMagenta);
            break;
        case DrawMode::DbgGray:
            if(m_heightField){
                set_pipeline(kDbgGrayHM);
            } else
                set_pipeline(kDbgGray);
            break;
        case DrawMode::DbgWhite:
            if(m_heightField){
                set_pipeline(kDbgWhiteHM);
            } else
                set_pipeline(kDbgWhite);
            break;
        }

        m_ubo.update();
    }

    void    HeightField³::snap(Rendered³Snap&sn) const
    {
        Rendered³::snap(sn);
        sn.model.xx = m_size.x;
        sn.model.yy = m_size.y;
        sn.model.zz = m_size.z;
    }


    Execution HeightField³::tick(const Context&ctx)
    {
        if(dirty())
            rebuild();
        return Rendered³::tick(ctx);
    }
    
    
}
