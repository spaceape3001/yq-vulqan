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
#include <yq/tachyon/asset/material/BasicMaterial.hpp>
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
            
            p.shader("yqvk/shape3/solid.vert");
            p.shader("yqvk/shape3/solid.frag");

            p.vertex(&Mesh³::m_vboS, DataActivity::DYNAMIC)
                .attribute(&VertexS::position)
            ;

            p.index(&Mesh³::m_ibo, DataActivity::DYNAMIC);
            p.uniform(&Mesh³::m_ubo, DataActivity::DYNAMIC);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p  = w.pipeline(Pipeline::Role::Textured);

            p.shader("yqvk/shape3/textured.vert");
            p.shader("yqvk/shape3/textured.frag");

            p.vertex(&Mesh³::m_vboT, DataActivity::DYNAMIC)
                .attribute(&VertexT::position)
                .attribute(&VertexT::uv)
            ;
            p.index(&Mesh³::m_ibo, DataActivity::DYNAMIC);
            p.uniform(&Mesh³::m_ubo, DataActivity::DYNAMIC);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }
    }

    Mesh³::Mesh³(const Param&p) : Shape³(p)
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
        if(!m_mesh || !m_mesh->is_3d() || m_mesh->xyz.empty()){
            m_good  = false;
            return;
        }
        
        size_t  N   = m_mesh->vertex(COUNT);
        
        // this detection will be moved to shape3 (after we see if it works...)
        bool    textured    = m_material && !dynamic_cast<const BasicMaterial*>(m_material.ptr());
        if(textured){
            set_pipeline(Pipeline::Role::Textured);
            m_vboT.data.clear();
            for(size_t n=0;n<N;++n)
                m_vboT.data.push_back(vtx(m_mesh->vertex3(n), m_mesh->texc2(n)));
            m_vboT.update();
        } else {
            set_pipeline(Pipeline::Role::SolidColor);
            m_vboS.data.clear();
            for(size_t n=0;n<N;++n)
                m_vboS.data.push_back(vtx(m_mesh->vertex3(n)));
            m_vboS.update();
        }
        
        
        if(m_mesh->index.empty()){
            m_ibo   = m_mesh->index;
        } else {
            m_ibo.data.clear();
            for(size_t n=0;n<N;++n)
                m_ibo.data.push_back((uint32_t) n);
            m_ibo.update();
        }
        
        m_ubo   = UBS{.color = gfx(color())};
    
        //  So far... six variations
        //
        //  Color   w&wo indices
        //  Texture w&wo indices
        //  Mesh    w&wo indices
    
    }

    Execution   Mesh³::setup(const Context&u) 
    {
        rebuild();
        return Shape³::setup(u);
    }
    
    Execution   Mesh³::tick(const Context&u)
    {
        if(dirty())
            rebuild();
        return Shape³::tick(u);
    }

}
