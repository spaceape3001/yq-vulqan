////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh3.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/aspect/AColorWriter.hxx>
#include <yq/tachyon/aspect/AMaterialWriter.hxx>
#include <yq/tachyon/aspect/AMeshWriter.hxx>
#include <yq/tachyon/aspect/ATextureWriter.hxx>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/material/BasicMaterial.hpp>
#include <yq/color/colors.hpp>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mesh³)

//#define NOISY_LOG   1

namespace yq::tachyon {
    void Mesh³::init_meta()
    {
        auto w = writer<Mesh³>();
        w.interface<ITopology>();
        w.interface<IVertices³>();
        AMesh::init_meta(w);
        
        {
            auto& p     = w.pipeline(Pipeline::Role::DbgBlack);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/black.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgRed);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/red.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgOrange);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/orange.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }
        
        {
            auto& p     = w.pipeline(Pipeline::Role::DbgYellow);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/yellow.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgGreen);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/green.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgBlue);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/blue.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgMagenta);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/magenta.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgGray);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/gray.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p     = w.pipeline(Pipeline::Role::DbgWhite);
            p.shader("yqvk/debug/position.vert");
            p.shader("yqvk/debug/color/white.frag");
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.vertex(&Mesh³::m_vxyz, {.activity=DYNAMIC});
            p.polygons(PolygonMode::Line);
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p  = w.pipeline(Pipeline::Role::SolidColor);
            
            p.shader("yqvk/shape3/solid.vert");
            p.shader("yqvk/shape3/solid.frag");

            p.vertex(&Mesh³::m_vboS, {.activity=DYNAMIC})
                .attribute(&VertexS::position)
            ;

            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.uniform(&Mesh³::m_ubo, {.activity=DYNAMIC});
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }

        {
            auto& p  = w.pipeline(Pipeline::Role::Textured);

            p.shader("yqvk/shape3/textured.vert");
            p.shader("yqvk/shape3/textured.frag");

            p.vertex(&Mesh³::m_vboT, {.activity=DYNAMIC})
                .attribute(&VertexT::position)
                .attribute(&VertexT::uv)
            ;
            p.index(&Mesh³::m_ibo, {.activity=DYNAMIC});
            p.uniform(&Mesh³::m_ubo, {.activity=DYNAMIC});
            p.dynamic_state(DynamicState::PrimitiveTopology);
            p.push_full();
        }
    }

    Mesh³::Mesh³(const Param&p) : Shape³(p)
    {
        m_color = rgba4f(color::Gray);          // default default
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


    void Mesh³::_import_normal()
    {
        size_t N = m_mesh->normal.size();
        m_vnormal.data.clear();
        m_vnormal.data.reserve(N);
        Vector3F    sgn = copysign(Vector3F(1., 1., 1.), m_meshScale);
        for(auto& v : m_mesh->normal)
            m_vnormal.data.push_back(gfx(remap(m_meshAxis, sgn.emul(v))));
        if(m_vnormal.data.size() < m_vxyz.data.size())
            m_vnormal.data.resize(m_vxyz.data.size(), { 0., 0., 0. });
        m_vnormal.update();
    }

    void Mesh³::_import_rgb()
    {
        size_t N = m_mesh->rgb.size();
        m_vcolor.data.clear();
        m_vcolor.data.reserve(N);
        for(auto& v : m_mesh->rgb)
            m_vcolor.data.push_back({v.red, v.green, v.blue, 1.f});
        if(m_vcolor.data.size() < m_vxyz.data.size())
            m_vcolor.data.resize(m_vxyz.data.size(), { 0., 0., 0., 0. });
        m_vcolor.update();
    }
    
    void Mesh³::_import_rgba()
    {
        size_t N = m_mesh->rgba.size();
        m_vcolor.data.clear();
        m_vcolor.data.reserve(N);
        for(auto& v : m_mesh->rgba)
            m_vcolor.data.push_back({v.red, v.green, v.blue, v.alpha});
        if(m_vcolor.data.size() < m_vxyz.data.size())
            m_vcolor.data.resize(m_vxyz.data.size(), { 0., 0., 0., 0. });
        m_vcolor.update();
    }
    
    void Mesh³::_import_uv()
    {
        size_t N = m_mesh->uv.size();
        m_vtex.data.clear();
        m_vtex.data.reserve(N);
        for(auto& v : m_mesh->uv)
            m_vtex.data.push_back({v.u, v.v});
        if(m_vtex.data.size() < m_vxyz.data.size())
            m_vtex.data.resize(m_vxyz.data.size(), { 0., 0. });
        m_vtex.update();
    }
    
    void Mesh³::_import_uvw()
    {
        size_t N = m_mesh->uvw.size();
        m_vtex.data.clear();
        m_vtex.data.reserve(N);
        for(auto& v : m_mesh->uvw)
            m_vtex.data.push_back({v.u, v.v});
        if(m_vtex.data.size() < m_vxyz.data.size())
            m_vtex.data.resize(m_vxyz.data.size(), { 0., 0. });
        m_vtex.update();
    }

    void Mesh³::_import_xyz()
    {
        size_t  N   = m_mesh->xyz.size();
        m_vxyz.data.clear();
        m_vxyz.data.reserve(N);
        for(auto& v : m_mesh->xyz)
            m_vxyz.data.push_back(gfx(remap(m_meshAxis, m_meshScale.emul(v - m_meshOrigin))));
        m_vxyz.update();
    }

    void Mesh³::rebuild()
    {
        if(!m_mesh){
            #ifdef NOISY_LOG
            tachyonInfo << ident() << "::rebuild: No mesh";
            #endif
            
            m_good  = false;
            return;
        }

        if(!m_mesh->is_3d()){
            tachyonFirstError(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Not a 3D mesh";
            m_good  = false;
            return;
        }
    
        if(m_mesh->index.empty()){
            tachyonFirstError(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): No indices";
            m_good  = false;
            return;
        }
        
        //  check for missing data
        
        if(m_mesh->rgb.size() && (m_mesh->rgb.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of RGB colors in the mesh.";
        if(m_mesh->rgba.size() && (m_mesh->rgba.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of RGBA colors in the mesh.";
        if(m_mesh->normal.size() && (m_mesh->normal.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of normals in the mesh.";
        if(m_mesh->tangent.size() && (m_mesh->tangent.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of tangents in the mesh.";
        if(m_mesh->tangent_b.size() && (m_mesh->tangent_b.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of B tangents in the mesh.";
        if(m_mesh->uv.size() && (m_mesh->uv.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of UV texture coordinates in the mesh.";
        if(m_mesh->uvw.size() && (m_mesh->uvw.size() != m_mesh->xyz.size()))
            tachyonFirstWarning(id(), m_mesh->id()) << ident() << "::rebuild(mesh=" << m_mesh->url() << "): Size mismatch, number of XYZ coordinates do not match the number of UVW texture coordinates in the mesh.";

        //size_t  N   = m_mesh->xyz.size();
        

        _import_xyz();
        m_ibo       = m_mesh->index;
        
        //  if there's an error....
        
        set_pipeline(Pipeline::Role::DbgYellow);
        m_good  = true;
        return ;
        

#if 0
        //size_t  N   = m_mesh->vertex(COUNT);
        m_ibo       = m_mesh->index;
 
        // this detection will be moved to shape3 (after we see if it works...)
        bool    textured    = m_material && !dynamic_cast<const BasicMaterial*>(m_material.ptr());
        if(textured){
            set_pipeline(Pipeline::Role::Textured);
            m_vboT.data.clear();
            for(size_t n=0;n<N;++n)
                m_vboT.data.push_back(vtx(m_mesh->vertex3(n), m_mesh->texc2(n)));
            m_vboT.update();

            #ifdef NOISY_LOG
            tachyonInfo << ident() << "::rebuild: " << m_vboT.data.size() << " verts, " << m_ibo.data.size() << " indices";
            #endif

        } else {
            set_pipeline(Pipeline::Role::SolidColor);
            m_vboS.data.clear();
            for(size_t n=0;n<N;++n)
                m_vboS.data.push_back(vtx(m_mesh->vertex3(n)));
            m_vboS.update();

            #ifdef NOISY_LOG
            tachyonInfo << ident() << "::rebuild: " << m_vboS.data.size() << " verts, " << m_ibo.data.size() << " indices";
            #endif
        }
        
        
        m_ubo   = UBS{.color = gfx(color())};


    
        //  So far... six variations
        //
        //  Color   w&wo indices
        //  Texture w&wo indices
        //  Mesh    w&wo indices
        
        m_good  = true;
    #endif
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


}
