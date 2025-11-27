////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh3.hpp"
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/aspect/AColorWriter.hxx>
#include <yq/tachyon/aspect/AMaterialWriter.hxx>
#include <yq/tachyon/aspect/AMeshWriter.hxx>
#include <yq/tachyon/aspect/ATextureWriter.hxx>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/color/colors.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mesh³)

namespace yq::tachyon {
    void Mesh³::init_meta()
    {
        auto w = writer<Mesh³>();
        w.interface<ITopology>();
        w.interface<IVertices³>();
        AColor::init_meta(w);
        AMaterial::init_meta(w);
        AMesh::init_meta(w);
        
        {
            auto& p  = w.pipeline(Pipeline::Role::SolidColor);
            
            p.shader("resources/shape3/color.vert");
            p.shader("resources/shape3/color.frag");
            p.vertex(&Mesh³::m_xyz, DataActivity::DYNAMIC);
            p.index(&Mesh³::m_ibo, DataActivity::DYNAMIC);
            p.uniform(&Mesh³::m_ubo, DataActivity::DYNAMIC);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p  = w.pipeline(Pipeline::Role::Textured);

            p.vertex(&Mesh³::m_xyz, DataActivity::DYNAMIC);
            p.vertex(&Mesh³::m_uv, DataActivity::DYNAMIC);
            p.index(&Mesh³::m_ibo, DataActivity::DYNAMIC);
            p.uniform(&Mesh³::m_ubo, DataActivity::DYNAMIC);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }
    }

    Mesh³::Mesh³(const Param&p) : Rendered³(p)
    {
        m_color = rgba4f(color::Gray);  // default default
        m_good  = false;
    }
    
    Mesh³::Mesh³(const MeshCPtr& mcp, const Param&p) : Mesh³(p)
    {
        m_mesh  = mcp;
        if(mcp && mcp -> material)
            m_material  = mcp->material;
        rebuild();
    }
    
    Mesh³::~Mesh³()
    {
    }

    Topology    Mesh³::topology() const 
    {
        if(!m_mesh)
            return Topology::PointList;
        return m_mesh -> topology;
    }

    size_t      Mesh³::vertices(count_k) const 
    {
        if(!m_mesh)
            return 0;
        return m_mesh -> xyz.size();
    }

    bool        Mesh³::vertices(color_k) const 
    {
        return m_mesh && !(m_mesh -> rgba.empty() && m_mesh->rgb.empty());
    }
    
    bool        Mesh³::vertices(tex_k) const 
    {
        return m_mesh && !(m_mesh -> uv.empty() && m_mesh->uvw.empty());
    }
    
    bool        Mesh³::vertices(normal_k) const 
    {
        return m_mesh && !m_mesh->normal.empty();
    }
    
    bool        Mesh³::vertices(point_k) const 
    {
        return m_mesh && !m_mesh->xyz.empty();
    }

    Vector3D    Mesh³::vertex(size_t n, point_k) const 
    {
        if(!m_mesh)
            return {};
        return m_mesh->vertex3(n).cast<double>();
    }
    
    RGBA4F      Mesh³::vertex(size_t n, color_k) const 
    {
        if(!m_mesh)
            return {};
        return m_mesh->color4(n);
    }
    
    UV2F        Mesh³::vertex(size_t n, tex_k) const 
    {
        if(!m_mesh)
            return {};
        return m_mesh -> texc2(n);
    }
    
    Vector3F    Mesh³::vertex(size_t n, normal_k) const 
    {
        if(!m_mesh)
            return {};
        return m_mesh -> normal3(n);
    }

    void Mesh³::rebuild()
    {
        if(!m_mesh){
            m_good  = false;
            return;
        }
        
        
        if(m_material){
            set_pipeline(Pipeline::Role::Default);  // ignore this case
        } else {
            set_pipeline(Pipeline::Role::SolidColor);
        }
        
        
    
        //  So far... six variations
        //
        //  Color   w&wo indices
        //  Texture w&wo indices
        //  Mesh    w&wo indices
    
    }

    
    Execution   Mesh³::setup(const Context&u) 
    {
        rebuild();
        return Rendered³::setup(u);
    }
    
    Execution   Mesh³::tick(const Context&u)
    {
        if(dirty())
            rebuild();
        return Rendered³::tick(u);
    }

}
