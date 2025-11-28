////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/container/vector_utils.hpp>
#include <yq/vector/Vector3.hxx>

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

    RGBA4F      Mesh::color4(size_t n) const
    {
        if(rgba.empty()){
            if(n >= rgb.size())
                return {};
            return yq::rgba(rgb[n], 1.);
        } else {
            if(n >= rgba.size())
                return {};
            return rgba[n];
        }
    }
    
    bool        Mesh::is_2d() const
    {
        return xyz.empty() && !xy.empty();
    }
    
    bool        Mesh::is_3d() const
    {
        return xy.empty() && !xyz.empty();
    }
    

    Vector3F    Mesh::normal3(size_t n) const
    {
        if(n >= normal.size())
            return {};
        return normal[n];
    }

    UV2F        Mesh::texc2(size_t n) const
    {
        if(uvw.empty()){
            if(n >= uv.size())
                return {};
            return uv[n];
        } else {
            if(n >= uvw.size()) 
                return {};
            auto& ret   = uvw[n];
            return UV2F(ret.u, ret.v);
        }
    }

    UVW3F       Mesh::texc3(size_t n) const
    {
        if(uvw.empty()){
            if(n >= uv.size())
                return {};
            auto& ret   = uv[n];
            return UVW3F(ret.u, ret.v, 0.);
        } else {
            if(n >= uvw.size()) 
                return {};
            return uvw[n];
        }
    }

    size_t  Mesh::vertex(count_k) const
    {
        if(!xyz.empty())
            return xyz.size();
        return xy.size();
    }


    Vector3F    Mesh::vertex3(size_t n) const
    {
        if(xyz.empty()){
            if(n >= xy.size())
                return {};
            return yq::xy(xy[n], 1.);
        } else {
            if(n >= xyz.size())
                return {};
            return xyz[n];
        }
    }
    
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Mesh)
