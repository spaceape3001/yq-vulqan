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
#include <yq/tachyon/aspect/AHeightFieldWriter.hxx>
#include <yq/tachyon/aspect/AMaterialWriter.hxx>
#include <yq/tachyon/aspect/ASize3Writer.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::HeightField³)

namespace yq::tachyon {
    void HeightField³::init_meta()
    {
        auto w = writer<HeightField³>();
        w.description("Height Field Render Object");
        AColor::init_meta(w);
        ACount²::init_meta(w);
        AHeightField::init_meta(w);
        AMaterial::init_meta(w);
        ASize³::init_meta(w);
        
        
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

        UV2D    uv(unsigned i, unsigned j) const
        {
            return { frac(X,i), frac(Y,j) };
        }
        
        Vector2D pos(unsigned i, unsigned j) const
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
        
        m_vboPos.data.resize(grid.posts(COUNT));
        for(unsigned j : grid.yext())
            for(unsigned i : grid.xext())
        {
            m_vboPos.data[grid.post(i,j)] = grid.pos(i,j).cast<float>();
            //vert.uv         = (UV2F) grid.uv(i,j);
            //vert.pos        = ;
        }
        m_vboPos.update();
        
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
