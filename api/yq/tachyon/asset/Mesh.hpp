////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/math/UV.hpp>
#include <yq/math/UVW.hpp>
#include <yq/shape/Polymesh3.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/data/Vertex3.hpp>
#include <yq/tachyon/pipeline/Topology.hpp>
#include <yq/tachyon/typedef/material.hpp>
#include <yq/tachyon/typedef/mesh.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    /*! \brief Mesh
    
        
    
    */
    class Mesh : public Resource {
        YQ_RESOURCE_DECLARE(Mesh, Resource)
    public:

        //  These are designed to be directly used on the pipeline.
        //  If two similar parameters are specified, the higher
        //  resolution will be used.  Also, the sizes are expected
        //  to match (XY/XYZ/RGB/RGBA/NORMAL).

        std::vector<uint32_t>   index;   
        MaterialCPtr            material;
        std::vector<Vector3F>   normal;     // normal (ie... along "w")
        std::vector<RGB3F>      rgb;
        std::vector<RGBA4F>     rgba;
        std::vector<Vector3F>   tangent;    // first tangent (along "u")
        std::vector<Vector3F>   tangent_b;  // second tangent (along "v")
        Topology                topology = Topology::TriangleList;
        std::vector<UV2F>       uv;
        std::vector<UVW3F>      uvw;
        std::vector<Vector2F>   xy;
        std::vector<Vector3F>   xyz;

        RGBA4F                  color4(size_t) const;
        Vector3F                normal3(size_t) const;
        UV2F                    texc2(size_t) const;
        UVW3F                   texc3(size_t) const;
        Vector3F                vertex3(size_t) const;
        
        size_t                  vertex(count_k) const;

            //  GLTF allows for multiple "primitives" per mesh
            //  And as we're separating those out, the source name & primitive
            //  index are here.  The "name()" is a merger of these two.

        std::string             source;         // name from the file
        unsigned                primitive = 0;  // index within that file
        
        size_t                  data_size() const override;
        
        Mesh();
        ~Mesh();
    
        static void init_meta();
    };
}

