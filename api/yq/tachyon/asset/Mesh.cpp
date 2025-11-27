////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/container/vector_utils.hpp>

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

    size_t  Mesh::data_size() const
    {
        return 
            byte_count(index) +
            byte_count(normal) +
            byte_count(rgb) +
            byte_count(rgba) +
            byte_count(uv) +
            byte_count(uvw) +
            byte_count(tangent) +
            byte_count(tangent_b) +
            byte_count(xy) +
            byte_count(xyz)
        ;
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Mesh)
