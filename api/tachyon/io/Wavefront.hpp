////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/math/UVW.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <filesystem>
#include <variant>

namespace yq::tachyon {
    namespace wavefront {
        using vertex_t = std::variant<std::monostate, Vector4D, UVW3D>;
        
        struct ObjectFile {
            const vertex_t&             vertex(int) const;
            const UVW3D&                texcoord(int) const;
            const Vector3D&             normal(int) const;
            
            std::vector<vertex_t>       vertices;
            std::vector<UVW3D>          texcoords;
            std::vector<Vector3D>       normals;
          
            
        };
    }
    
    class WavefrontObject : public Resource {
    public:
    
    
    private:
    
    };
}
