////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <tachyon/data/Vertex3.hpp>
#include <tachyon/typedef/material_spec.hpp>
#include <tachyon/typedef/mesh.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/math/UV.hpp>
#include <yq/shape/Polymesh3.hpp>
#include <yq/vector/Vector3.hpp>


namespace yq::tachyon {

    /*! \brief Mesh... and we'll limit ourselves to 4-billion indices....
    */
    class Mesh : public Resource {
        YQ_RESOURCE_DECLARE(Mesh, Resource)
    public:
    
        struct Primitive;
        std::vector<Primitive>              primitives;
        std::vector<double>                 weights;        // morph targets
        
        #if 0
    
        static constexpr const RGBA4F    kBadColor   = { NAN, NAN, NAN, NAN };

        enum class C : uint8_t {
            Mesh        = 0,
            Vertex,
            Face,
            Line,
            Point
            
            //  If this goes to 8, then index needs to be adjusted
        };
        
        static constexpr size_t index(C c, unsigned i)
        {
            return (((size_t) i) << 3) | (size_t) c; // if we have more... we'll expand
        }
        
        Polymesh3D                              mesh;    //!< The actual polyhedral mesh (vertices & indices)
        std::unordered_map<size_t, Url>         materials;
        std::unordered_map<size_t, RGBA4F>      colors;
        std::unordered_map<size_t, RGBA4F>      dopes;
        std::unordered_map<size_t, UV2F>        uvs;
        std::unordered_map<size_t, Vector3F>    normals;
        std::unordered_map<size_t, Vector3F>    tangents;
        std::unordered_map<size_t, double>      weights;

                //  Just queries into the above
        RGBA4F      color(size_t) const;
        RGBA4F      dope(size_t) const;
        UrlView     material(size_t) const;
        Vector3F    tangent(size_t) const;
        Vector3F    normal(size_t) const;
        double      weight(size_t) const;
        UV2F        uv(size_t) const;

#endif
        
//        const Url&                      material_url() const { return m_material; }
        
        Mesh();
        ~Mesh();
        
    
        static void init_meta();
        
        #if 0
    
        static Mesh*        extract_from_obj(const std::filesystem::path&);
        static Mesh*        load_from_tmesh(const XmlDocument&);
        static bool         save_to_tmesh(const Mesh&, XmlDocument&);
        static Mesh*        read_from_tmesh(const XmlNode&);
        static bool         write_to_tmesh(const Mesh&, XmlNode&);
        
        RGBA4F              color(mesh_k) const;
        RGBA4F              color(vertex_k, unsigned) const;
        RGBA4F              color(line_k, unsigned) const;
        RGBA4F              color(face_k, unsigned) const;
        RGBA4F              color(point_k, unsigned) const;

        void                color(set_k, mesh_k, const RGBA4F&);
        void                color(set_k, vertex_k, unsigned, const RGBA4F&);
        void                color(set_k, line_k, unsigned, const RGBA4F&);
        void                color(set_k, face_k, unsigned, const RGBA4F&);
        void                color(set_k, point_k, unsigned, const RGBA4F&);

        void                color(erase_k, mesh_k);
        void                color(erase_k, vertex_k, unsigned);
        void                color(erase_k, line_k, unsigned);
        void                color(erase_k, face_k, unsigned);
        void                color(erase_k, point_k, unsigned);

        RGBA4F              dope(mesh_k) const;
        RGBA4F              dope(vertex_k, unsigned) const;
        RGBA4F              dope(line_k, unsigned) const;
        RGBA4F              dope(face_k, unsigned) const;
        RGBA4F              dope(point_k, unsigned) const;

        void                dope(set_k, mesh_k, const RGBA4F&);
        void                dope(set_k, vertex_k, unsigned, const RGBA4F&);
        void                dope(set_k, line_k, unsigned, const RGBA4F&);
        void                dope(set_k, face_k, unsigned, const RGBA4F&);
        void                dope(set_k, point_k, unsigned, const RGBA4F&);

        void                dope(erase_k, mesh_k);
        void                dope(erase_k, vertex_k, unsigned);
        void                dope(erase_k, line_k, unsigned);
        void                dope(erase_k, face_k, unsigned);
        void                dope(erase_k, point_k, unsigned);

        bool                has_colors() const;
        bool                has_dopes() const;
        bool                has_uvs() const;
        bool                has_normals() const;
        bool                has_weights() const;
        bool                has_tangents() const;
        bool                has_materials() const;
        
        UrlView             material(mesh_k) const;
        UrlView             material(vertex_k, unsigned) const;
        UrlView             material(line_k, unsigned) const;
        UrlView             material(face_k, unsigned) const;
        UrlView             material(point_k, unsigned) const;

        void                material(set_k, mesh_k, const UrlView&);
        void                material(set_k, vertex_k, unsigned, const UrlView&);
        void                material(set_k, line_k, unsigned, const UrlView&);
        void                material(set_k, face_k, unsigned, const UrlView&);
        void                material(set_k, point_k, unsigned, const UrlView&);        
        
        void                material(erase_k, mesh_k);
        void                material(erase_k, vertex_k, unsigned);
        void                material(erase_k, line_k, unsigned);
        void                material(erase_k, face_k, unsigned);
        void                material(erase_k, point_k, unsigned);

        Vector3F            normal(mesh_k) const;
        Vector3F            normal(vertex_k, unsigned) const;
        Vector3F            normal(line_k, unsigned) const;
        Vector3F            normal(face_k, unsigned) const;
        Vector3F            normal(point_k, unsigned) const;

        void                normal(set_k, mesh_k, const Vector3F&);
        void                normal(set_k, vertex_k, unsigned, const Vector3F&);
        void                normal(set_k, line_k, unsigned, const Vector3F&);
        void                normal(set_k, face_k, unsigned, const Vector3F&);
        void                normal(set_k, point_k, unsigned, const Vector3F&);

        void                normal(erase_k, mesh_k);
        void                normal(erase_k, vertex_k, unsigned);
        void                normal(erase_k, line_k, unsigned);
        void                normal(erase_k, face_k, unsigned);
        void                normal(erase_k, point_k, unsigned);

        Vector3F            tangent(mesh_k) const;
        Vector3F            tangent(vertex_k, unsigned) const;
        Vector3F            tangent(line_k, unsigned) const;
        Vector3F            tangent(face_k, unsigned) const;
        Vector3F            tangent(point_k, unsigned) const;

        void                tangent(set_k, mesh_k, const Vector3F&);
        void                tangent(set_k, vertex_k, unsigned, const Vector3F&);
        void                tangent(set_k, line_k, unsigned, const Vector3F&);
        void                tangent(set_k, face_k, unsigned, const Vector3F&);
        void                tangent(set_k, point_k, unsigned, const Vector3F&);

        void                tangent(erase_k, mesh_k);
        void                tangent(erase_k, vertex_k, unsigned);
        void                tangent(erase_k, line_k, unsigned);
        void                tangent(erase_k, face_k, unsigned);
        void                tangent(erase_k, point_k, unsigned);

        UV2F                uv(mesh_k) const;
        UV2F                uv(vertex_k, unsigned) const;
        UV2F                uv(line_k, unsigned) const;
        UV2F                uv(face_k, unsigned) const;
        UV2F                uv(point_k, unsigned) const;

        void                uv(set_k, mesh_k, const UV2F&);
        void                uv(set_k, vertex_k, unsigned, const UV2F&);
        void                uv(set_k, line_k, unsigned, const UV2F&);
        void                uv(set_k, face_k, unsigned, const UV2F&);
        void                uv(set_k, point_k, unsigned, const UV2F&);

        void                uv(erase_k, mesh_k);
        void                uv(erase_k, vertex_k, unsigned);
        void                uv(erase_k, line_k, unsigned);
        void                uv(erase_k, face_k, unsigned);
        void                uv(erase_k, point_k, unsigned);

        double              weight(mesh_k) const;
        double              weight(vertex_k, unsigned) const;
        double              weight(line_k, unsigned) const;
        double              weight(face_k, unsigned) const;
        double              weight(point_k, unsigned) const;

        void                weight(set_k, mesh_k, double);
        void                weight(set_k, vertex_k, unsigned, double);
        void                weight(set_k, line_k, unsigned, double);
        void                weight(set_k, face_k, unsigned, double);
        void                weight(set_k, point_k, unsigned, double);

        void                weight(erase_k, mesh_k);
        void                weight(erase_k, vertex_k, unsigned);
        void                weight(erase_k, line_k, unsigned);
        void                weight(erase_k, face_k, unsigned);
        void                weight(erase_k, point_k, unsigned);
        #endif
    };

    struct Mesh::Primitive {
        enum class Type : uint8_t {
            Unknown = 0,
            Points,
            Lines,
            LineLoop,
            LineStrip,
            Triangles,
            TriangleStrip,
            TriangleFan
        };
        
        
        Type                type = Type::Unknown;
        MaterialSpecCPtr    material;
        
        Primitive();
        ~Primitive();
    };

}

