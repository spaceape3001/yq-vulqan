////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HeightField3.hpp"
#include <yq/tachyon/api/Math.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/pipeline/DrawCall.hpp>

#include <yq/tachyon/aspect/AColorWriter.hxx>
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
        AHeightField::init_meta(w);
        AMaterial::init_meta(w);
        ASize³::init_meta(w);
        
        {
            auto p = w.pipeline();
            p.shaders({ "heightfield3/default.vert", "debug/color/cyan.frag" });
            p.topology(Topology::TriangleStrip);
            p.vertex(&HeightField³::m_vboPos, {.activity=DYNAMIC});
            p.index(&HeightField³::m_index);
            p.polygons(PolygonMode::Line);
        }
    }

    HeightField³::HeightField³() : HeightField³(Param())
    {
    }
    
    HeightField³::HeightField³(const Param& p) : Rendered³(Param())
    {
    }
    
    HeightField³::~HeightField³()
    {
    }

    bool HeightField³::good_heightfield() const
    {
        if(!m_heightField)
            return false;
        if(m_heightField->images.size() != 1)
            return false;
        
        if(!m_heightField->images[0])
            return false;
            
        auto& ras = *(m_heightField->images[0]);
        if(ras.info.size.x < 2)
            return false;
        if(ras.info.size.y < 2)
            return false;
        if(ras.info.size.z > 1)
            return false;
        if(ras.info.size.w > 1)
            return false;
        return true;
    }
    
    void    HeightField³::rebuild()
    {
        if(!good_heightfield()){
            m_good = false;
            return ;
        }
            
        const Size4U&  size = m_heightField->images[0]->info.size;
        size_t  cnt = (size_t) size.x * (size_t) size.y;
        
        
        
        m_verts.data.resize(cnt, {});
        m_index.data.clear();
        for(unsigned j=0;j<size.y;++j){
            for(unsigned i=0;i<size.x;++i)
            {
                uint32_t    idx = i*size.y + j;
                auto& vert  = m_verts.data[idx]; // think this is right... TBD
                vert.uv.x   = (float)((double)(size.x - 1.0) * i);
                vert.uv.y   = (float)((double)(size.y - 1.0) * j);
                vert.pos.x  = (float)(2.0 * vert.uv.x - 0.5);
                vert.pos.y  = (float)(2.0 * vert.uv.y - 0.5);
            }
        
        }
        m_verts.update();

        m_indexDraws.clear();
        for(unsigned j=1;j<size.y;++j){
            uint32_t    n   = (uint32_t) m_index.data.size();
            for(unsigned i=0;i<size.x;++i){
                uint32_t    idx = i*size.y + j;
                m_index.data.push_back(idx);
                m_index.data.push_back(idx-size.x);
            }
            uint32_t    n1  = (uint32_t) m_index.data.size();
            m_indexDraws.push_back({
                .index_count    = n1 - n,
                .first_index    = n
            });
        }
        m_index.update();
        
        mark();
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
