////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/UVW.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <variant>
#include <system_error>

#ifdef NAN
#undef NAN
#endif

namespace yq {
    class Stream;
}

/*
    This is file about implementing a wavefront object reader/writer
*/

namespace yq::tachyon::wavefront {
    struct BlankLine {};

    struct Comment {
        std::string     text;
    };
    
    struct GeometryVertex {
        Vector4D        point = NAN;  // NANs for the unspecified points
    };
    
    struct TextureCoordinate {
        UVW3D           uvw = NAN;
    };
    
    struct VertexNormal {
        Vector3D        normal = NAN;
    };
    
    struct VertexSpec {
        int vertex  = 0;
        int texc    = 0;
        int normal  = 0;
    };
    
    struct PolygonFace {
        std::vector<VertexSpec> vertices;
    };
    
    struct LineElement {
        std::vector<int>        vertices;
    };
    
    struct ObjectName {
        std::string         name;
    };
    
    struct PolygonGroup {
        std::string         name;
    };
    
    struct SmoothingGroup {
        std::string         name;  // "off" is disabling it
    };
    
    struct MaterialLibrary {
        std::string         file;
    };
    
    struct UseMaterial {
        std::string         material;
    };

    struct ParameterizedVertex {
        UVW3D           vertex  = NAN;
    };

    using Line  = std::variant<
        std::monostate,             // noop
        BlankLine,
        Comment,
        GeometryVertex,
        ParameterizedVertex,
        TextureCoordinate,
        PolygonFace,
        LineElement,
        ObjectName,
        PolygonGroup,
        SmoothingGroup,
        MaterialLibrary,
        UseMaterial,
        VertexNormal
    >;
    
    struct ObjFileData {
        std::vector<Line>       lines;
    };
    
    std::error_code     parse_object_data(ObjFileData&, std::string_view);
    std::error_code     write_object_data(Stream&, const ObjFileData&);
}
