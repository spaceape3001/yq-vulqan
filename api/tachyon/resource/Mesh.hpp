////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/data/Vertex3.hpp>
#include <tachyon/typedef/mesh.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>
#include <yq/math/UV.hpp>
#include <yq/math/UVW.hpp>
#include <yq/vector/Vector3.hpp>


namespace yq::tachyon {

    YQ_ENUM(MeshFlag, , 
        Weight,
        Normal,
        TexCoord,
        TexWeight,
        Color,
        Dope,
        Clockwise
    )

    using MeshFlags = Flag<MeshFlag>;

    class Mesh : public Resource {
        YQ_RESOURCE_DECLARE(Mesh, Resource)
    public:
        using Color = RGBA4F;
        using Index = uint32_t;
        
        static constexpr const Color    kBadColor   = { NAN, NAN, NAN, NAN };
        static constexpr const Index    kBadIndex   = UINT32_MAX;
        
        struct Properties {
            Url         material;
            Color       color       = kBadColor; 
            Color       dope        = kBadColor;    // color tweak, multiplies all terms
            string_any_multimap_t   attributes;
        };
    
        struct Face : public Properties {
            std::vector<uint32_t>       index;     //! From the vertices
        };
        
        struct Line : public Properties  {
            std::vector<uint32_t>       index;     //! From the vertices
        };
    
        struct Point : public Properties  {
            uint32_t                    index  = kBadIndex;
        };
    
        struct Vertex : public Properties  {
            Vector3D        vertex      = NAN;
            double          vweight     = NAN;
            UV2F            uv          = NAN;
            Vector3F        normal      = NAN;
            Vector3F        tangent     = NAN;
        };
    
//        const Url&                      material_url() const { return m_material; }
        
        const std::vector<Vertex>&      vertices() const { return m_vertices; }
        const std::vector<Face>&        faces() const { return m_faces; }
        const std::vector<Line>&        lines() const { return m_lines; }
        const std::vector<Point>&       points() const { return m_points; }
        const Properties&               properties() const { return m_properties; }
        
        bool        is_ccw() const;
        
        MeshFlags    flags() const { return m_flags; }
        
        Mesh();
        ~Mesh();
        
        void    add(const Face&);
        void    add(const Vertex&);
        void    add(const Line&);
        void    add(const Point&);

        void    add(Face&&);
        void    add(Vertex&&);
        void    add(Line&&);
        void    add(Point&&);

        const Url&                  material_url() const { return m_properties.material; }
        
        static void init_meta();
    
        MeshPtr     extract_from_obj(const std::filesystem::path&);
    
    private:

        std::vector<Vertex>         m_vertices;
        std::vector<Face>           m_faces;
        std::vector<Line>           m_lines;
        std::vector<Point>          m_points;
        Properties                  m_properties;
        MeshFlags                   m_flags;
    };
    
    
    
}

