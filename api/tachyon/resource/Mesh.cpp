////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Mesh)

namespace yq::tachyon {

    void Mesh::init_meta()
    {
        auto w = writer<Mesh>();
        w.description("Polyhedral Mesh");
    }
    
    Mesh::Mesh()
    {
    }
    
    Mesh::~Mesh()
    {
    }
    
    void    Mesh::add(const Face& f)
    {
        m_faces.push_back(f);
    }
    
    void    Mesh::add(const Vertex&v)
    {
        m_vertices.push_back(v);
    }
    
    void    Mesh::add(const Line&l)
    {
        m_lines.push_back(l);
    }
    
    void    Mesh::add(const Point&p)
    {   
        m_points.push_back(p);
    }


    void    Mesh::add(Face&&f)
    {
        m_faces.push_back(std::move(f));
    }
    
    void    Mesh::add(Vertex&&v)
    {
        m_vertices.push_back(std::move(v));
    }
    
    void    Mesh::add(Line&&l)
    {
        m_lines.push_back(std::move(l));
    }
    
    void    Mesh::add(Point&&p)
    {
        m_points.push_back(std::move(p));
    }

    bool    Mesh::is_ccw() const
    {
        return !m_flags(MeshFlag::Clockwise);
    }
    
}
