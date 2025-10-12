////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

#undef NAN

namespace yq::tachyon {
    void Mesh::init_meta()
    {
        auto w = writer<Mesh>();
        w.description("Mesh");
    }
    
    Mesh::Mesh()
    {
    }
    
    Mesh::~Mesh()
    {
    }
    
    RGBA4F       Mesh::color(size_t i) const
    {
        auto k = colors.find(i);
        if(k != colors.end())
            return k->second;
        return kBadColor;
    }
    
    RGBA4F              Mesh::color(mesh_k) const
    {
        return color(0);
    }
    
    RGBA4F              Mesh::color(vertex_k, unsigned i) const
    {
        return color(index(C::Vertex, i));
    }
    
    RGBA4F              Mesh::color(line_k, unsigned i) const
    {
        return color(index(C::Line, i));
    }
    
    RGBA4F              Mesh::color(face_k, unsigned i) const
    {
        return color(index(C::Face, i));
    }
    
    RGBA4F              Mesh::color(point_k, unsigned i) const
    {
        return color(index(C::Point, i));
    }

    void                Mesh::color(set_k, mesh_k, const RGBA4F&v)
    {
        colors[0]   = v;
    }
    
    void                Mesh::color(set_k, vertex_k, unsigned i, const RGBA4F&v)
    {
        colors[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::color(set_k, line_k, unsigned i, const RGBA4F&v)
    {
        colors[index(C::Line,i)] = v;
    }
    
    void                Mesh::color(set_k, face_k, unsigned i, const RGBA4F&v)
    {
        colors[index(C::Face,i)]  = v;
    }
    
    void                Mesh::color(set_k, point_k, unsigned i, const RGBA4F&v)
    {
        colors[index(C::Point,i)] = v;
    }

    void                Mesh::color(erase_k, mesh_k)
    {
        colors.erase(index(C::Mesh,0));
    }
    
    void                Mesh::color(erase_k, vertex_k, unsigned i)
    {
        colors.erase(index(C::Vertex, i));
    }
    
    void                Mesh::color(erase_k, line_k, unsigned i)
    {
        colors.erase(index(C::Line, i));
    }
    
    void                Mesh::color(erase_k, face_k, unsigned i)
    {
        colors.erase(index(C::Face, i));
    }
    
    void                Mesh::color(erase_k, point_k, unsigned i)
    {
        colors.erase(index(C::Point, i));
    }


    RGBA4F       Mesh::dope(size_t i) const
    {
        auto k = dopes.find(i);
        if(k != dopes.end())
            return k->second;
        return kBadColor;
    }
    
    RGBA4F              Mesh::dope(mesh_k) const
    {
        return dope(0);
    }
    
    RGBA4F              Mesh::dope(vertex_k, unsigned i) const
    {
        return dope(index(C::Vertex, i));
    }
    
    RGBA4F              Mesh::dope(line_k, unsigned i) const
    {
        return dope(index(C::Line, i));
    }
    
    RGBA4F              Mesh::dope(face_k, unsigned i) const
    {
        return dope(index(C::Face, i));
    }
    
    RGBA4F              Mesh::dope(point_k, unsigned i) const
    {
        return dope(index(C::Point, i));
    }

    void                Mesh::dope(set_k, mesh_k, const RGBA4F&v)
    {
        dopes[0]   = v;
    }
    
    void                Mesh::dope(set_k, vertex_k, unsigned i, const RGBA4F&v)
    {
        dopes[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::dope(set_k, line_k, unsigned i, const RGBA4F&v)
    {
        dopes[index(C::Line,i)] = v;
    }
    
    void                Mesh::dope(set_k, face_k, unsigned i, const RGBA4F&v)
    {
        dopes[index(C::Face,i)]  = v;
    }
    
    void                Mesh::dope(set_k, point_k, unsigned i, const RGBA4F&v)
    {
        dopes[index(C::Point,i)] = v;
    }

    void                Mesh::dope(erase_k, mesh_k)
    {
        dopes.erase(index(C::Mesh,0));
    }
    
    void                Mesh::dope(erase_k, vertex_k, unsigned i)
    {
        dopes.erase(index(C::Vertex, i));
    }
    
    void                Mesh::dope(erase_k, line_k, unsigned i)
    {
        dopes.erase(index(C::Line, i));
    }
    
    void                Mesh::dope(erase_k, face_k, unsigned i)
    {
        dopes.erase(index(C::Face, i));
    }
    
    void                Mesh::dope(erase_k, point_k, unsigned i)
    {
        dopes.erase(index(C::Point, i));
    }

    bool                Mesh::has_colors() const
    {
        return !colors.empty();
    }
    
    bool                Mesh::has_dopes() const
    {
        return !dopes.empty();
    }
    
    bool                Mesh::has_materials() const
    {
        return !materials.empty();
    }
    
    bool                Mesh::has_normals() const
    {
        return !normals.empty();
    }
    
    bool                Mesh::has_tangents() const
    {
        return !tangents.empty();
    }
    
    bool                Mesh::has_uvs() const
    {
        return !uvs.empty();
    }
    
    bool                Mesh::has_weights() const
    {
        return !weights.empty();
    }

    UrlView     Mesh::material(size_t i) const
    {
        auto k = materials.find(i);
        if(k != materials.end())
            return k->second;
        return {};
    }
    
    
    UrlView             Mesh::material(mesh_k) const
    {
        return material(0);
    }
    
    UrlView             Mesh::material(vertex_k, unsigned i) const
    {
        return material(index(C::Vertex, i));
    }
    
    UrlView             Mesh::material(line_k, unsigned i) const
    {
        return material(index(C::Line, i));
    }
    
    UrlView             Mesh::material(face_k, unsigned i) const
    {
        return material(index(C::Face, i));
    }
    
    UrlView             Mesh::material(point_k, unsigned i) const
    {
        return material(index(C::Point, i));
    }
    
    void                Mesh::material(set_k, mesh_k, const UrlView&v)
    {
        materials[0]   = copy(v);
    }
    
    void                Mesh::material(set_k, vertex_k, unsigned i, const UrlView&v)
    {
        materials[index(C::Vertex,i)] = copy(v);
    }
    
    void                Mesh::material(set_k, line_k, unsigned i, const UrlView&v)
    {
        materials[index(C::Line,i)] = copy(v);
    }
    
    void                Mesh::material(set_k, face_k, unsigned i, const UrlView&v)
    {
        materials[index(C::Face,i)]  = copy(v);
    }
    
    void                Mesh::material(set_k, point_k, unsigned i, const UrlView&v)
    {
        materials[index(C::Point,i)] = copy(v);
    }

    void                Mesh::material(erase_k, mesh_k)
    {
        materials.erase(index(C::Mesh,0));
    }
    
    void                Mesh::material(erase_k, vertex_k, unsigned i)
    {
        materials.erase(index(C::Vertex, i));
    }
    
    void                Mesh::material(erase_k, line_k, unsigned i)
    {
        materials.erase(index(C::Line, i));
    }
    
    void                Mesh::material(erase_k, face_k, unsigned i)
    {
        materials.erase(index(C::Face, i));
    }
    
    void                Mesh::material(erase_k, point_k, unsigned i)
    {
        materials.erase(index(C::Point, i));
    }

    Vector3F    Mesh::normal(size_t i) const
    {
        auto k = normals.find(i);
        if(k!=normals.end())
            return k->second;
        return NAN;
    }
    
    Vector3F              Mesh::normal(mesh_k) const
    {
        return normal(0);
    }
    
    Vector3F              Mesh::normal(vertex_k, unsigned i) const
    {
        return normal(index(C::Vertex, i));
    }
    
    Vector3F              Mesh::normal(line_k, unsigned i) const
    {
        return normal(index(C::Line, i));
    }
    
    Vector3F              Mesh::normal(face_k, unsigned i) const
    {
        return normal(index(C::Face, i));
    }
    
    Vector3F              Mesh::normal(point_k, unsigned i) const
    {
        return normal(index(C::Point, i));
    }

    void                Mesh::normal(set_k, mesh_k, const Vector3F&v)
    {
        normals[0]   = v;
    }
    
    void                Mesh::normal(set_k, vertex_k, unsigned i, const Vector3F&v)
    {
        normals[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::normal(set_k, line_k, unsigned i, const Vector3F&v)
    {
        normals[index(C::Line,i)] = v;
    }
    
    void                Mesh::normal(set_k, face_k, unsigned i, const Vector3F&v)
    {
        normals[index(C::Face,i)]  = v;
    }
    
    void                Mesh::normal(set_k, point_k, unsigned i, const Vector3F&v)
    {
        normals[index(C::Point,i)] = v;
    }

    void                Mesh::normal(erase_k, mesh_k)
    {
        normals.erase(index(C::Mesh,0));
    }
    
    void                Mesh::normal(erase_k, vertex_k, unsigned i)
    {
        normals.erase(index(C::Vertex, i));
    }
    
    void                Mesh::normal(erase_k, line_k, unsigned i)
    {
        normals.erase(index(C::Line, i));
    }
    
    void                Mesh::normal(erase_k, face_k, unsigned i)
    {
        normals.erase(index(C::Face, i));
    }
    
    void                Mesh::normal(erase_k, point_k, unsigned i)
    {
        normals.erase(index(C::Point, i));
    }


    Vector3F    Mesh::tangent(size_t i) const
    {
        auto k = tangents.find(i);
        if(k != tangents.end())
            return k->second;
        return NAN;
    }

    
    Vector3F              Mesh::tangent(mesh_k) const
    {
        return tangent(0);
    }
    
    Vector3F              Mesh::tangent(vertex_k, unsigned i) const
    {
        return tangent(index(C::Vertex, i));
    }
    
    Vector3F              Mesh::tangent(line_k, unsigned i) const
    {
        return tangent(index(C::Line, i));
    }
    
    Vector3F              Mesh::tangent(face_k, unsigned i) const
    {
        return tangent(index(C::Face, i));
    }
    
    Vector3F              Mesh::tangent(point_k, unsigned i) const
    {
        return tangent(index(C::Point, i));
    }

    void                Mesh::tangent(set_k, mesh_k, const Vector3F&v)
    {
        tangents[0]   = v;
    }
    
    void                Mesh::tangent(set_k, vertex_k, unsigned i, const Vector3F&v)
    {
        tangents[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::tangent(set_k, line_k, unsigned i, const Vector3F&v)
    {
        tangents[index(C::Line,i)] = v;
    }
    
    void                Mesh::tangent(set_k, face_k, unsigned i, const Vector3F&v)
    {
        tangents[index(C::Face,i)]  = v;
    }
    
    void                Mesh::tangent(set_k, point_k, unsigned i, const Vector3F&v)
    {
        tangents[index(C::Point,i)] = v;
    }

    void                Mesh::tangent(erase_k, mesh_k)
    {
        tangents.erase(index(C::Mesh,0));
    }
    
    void                Mesh::tangent(erase_k, vertex_k, unsigned i)
    {
        tangents.erase(index(C::Vertex, i));
    }
    
    void                Mesh::tangent(erase_k, line_k, unsigned i)
    {
        tangents.erase(index(C::Line, i));
    }
    
    void                Mesh::tangent(erase_k, face_k, unsigned i)
    {
        tangents.erase(index(C::Face, i));
    }
    
    void                Mesh::tangent(erase_k, point_k, unsigned i)
    {
        tangents.erase(index(C::Point, i));
    }
    
    UV2F        Mesh::uv(size_t i) const
    {
        auto k = uvs.find(i);
        if(k != uvs.end())
            return k->second;
        return NAN;
    }

    UV2F              Mesh::uv(mesh_k) const
    {
        return uv(0);
    }
    
    UV2F              Mesh::uv(vertex_k, unsigned i) const
    {
        return uv(index(C::Vertex, i));
    }
    
    UV2F              Mesh::uv(line_k, unsigned i) const
    {
        return uv(index(C::Line, i));
    }
    
    UV2F              Mesh::uv(face_k, unsigned i) const
    {
        return uv(index(C::Face, i));
    }
    
    UV2F              Mesh::uv(point_k, unsigned i) const
    {
        return uv(index(C::Point, i));
    }

    void                Mesh::uv(set_k, mesh_k, const UV2F&v)
    {
        uvs[0]   = v;
    }
    
    void                Mesh::uv(set_k, vertex_k, unsigned i, const UV2F&v)
    {
        uvs[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::uv(set_k, line_k, unsigned i, const UV2F&v)
    {
        uvs[index(C::Line,i)] = v;
    }
    
    void                Mesh::uv(set_k, face_k, unsigned i, const UV2F&v)
    {
        uvs[index(C::Face,i)]  = v;
    }
    
    void                Mesh::uv(set_k, point_k, unsigned i, const UV2F&v)
    {
        uvs[index(C::Point,i)] = v;
    }

    void                Mesh::uv(erase_k, mesh_k)
    {
        uvs.erase(index(C::Mesh,0));
    }
    
    void                Mesh::uv(erase_k, vertex_k, unsigned i)
    {
        uvs.erase(index(C::Vertex, i));
    }
    
    void                Mesh::uv(erase_k, line_k, unsigned i)
    {
        uvs.erase(index(C::Line, i));
    }
    
    void                Mesh::uv(erase_k, face_k, unsigned i)
    {
        uvs.erase(index(C::Face, i));
    }
    
    void                Mesh::uv(erase_k, point_k, unsigned i)
    {
        uvs.erase(index(C::Point, i));
    }

    double    Mesh::weight(size_t i) const
    {
        auto k = weights.find(i);
        if(k!=weights.end())
            return k->second;
        return NAN;
    }

    double              Mesh::weight(mesh_k) const
    {
        return weight(0);
    }
    
    double              Mesh::weight(vertex_k, unsigned i) const
    {
        return weight(index(C::Vertex, i));
    }
    
    double              Mesh::weight(line_k, unsigned i) const
    {
        return weight(index(C::Line, i));
    }
    
    double              Mesh::weight(face_k, unsigned i) const
    {
        return weight(index(C::Face, i));
    }
    
    double              Mesh::weight(point_k, unsigned i) const
    {
        return weight(index(C::Point, i));
    }

    void                Mesh::weight(set_k, mesh_k, double v)
    {
        weights[0]   = v;
    }
    
    void                Mesh::weight(set_k, vertex_k, unsigned i, double v)
    {
        weights[index(C::Vertex,i)] = v;
    }
    
    void                Mesh::weight(set_k, line_k, unsigned i, double v)
    {
        weights[index(C::Line,i)] = v;
    }
    
    void                Mesh::weight(set_k, face_k, unsigned i, double v)
    {
        weights[index(C::Face,i)]  = v;
    }
    
    void                Mesh::weight(set_k, point_k, unsigned i, double v)
    {
        weights[index(C::Point,i)] = v;
    }

    void                Mesh::weight(erase_k, mesh_k)
    {
        weights.erase(index(C::Mesh,0));
    }
    
    void                Mesh::weight(erase_k, vertex_k, unsigned i)
    {
        weights.erase(index(C::Vertex, i));
    }
    
    void                Mesh::weight(erase_k, line_k, unsigned i)
    {
        weights.erase(index(C::Line, i));
    }
    
    void                Mesh::weight(erase_k, face_k, unsigned i)
    {
        weights.erase(index(C::Face, i));
    }
    
    void                Mesh::weight(erase_k, point_k, unsigned i)
    {
        weights.erase(index(C::Point, i));
    }

#if 0

    Vector3D            Mesh::vertex(unsigned i) const;
    void                Mesh::vertex(set_k, unsigned i, const Vector3D&v) const;
    void                Mesh::vertex(erase_k, unsigned i) const;
#endif

}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Mesh)
