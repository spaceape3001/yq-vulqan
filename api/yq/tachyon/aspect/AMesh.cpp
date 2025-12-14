////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMesh.hpp"
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/command/mesh/SetMeshCommand.hpp>
#include <yq/tachyon/command/mesh/SetMeshSpecCommand.hpp>
#include <yq/tachyon/command/mesh/SetMeshUrlCommand.hpp>
#include <yq/tachyon/event/SetMeshEvent.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    AMesh::AMesh()
    {
    }
    
    AMesh::~AMesh()
    {
    }

    MeshCPtr        AMesh::mesh() const
    {
        return m_mesh;
    }

    Url         AMesh::mesh(url_k) const 
    {
        return m_meshUrl;
    }

    void        AMesh::mesh(emit_k)
    {
        send(new SetMeshEvent({.source=typed()}, m_mesh, m_meshUrl));
    }
    
    void        AMesh::mesh(set_k, const MeshCPtr& tex) 
    {
        m_mesh           = tex;
        m_meshUrl        = tex ? tex->url() : Url();
        mark();
        mesh(EMIT);
    }
    
    void        AMesh::mesh(set_k, const Url& u)
    {
        m_meshUrl    = u;
        if(u.empty()){
            m_mesh   = {};
        } else {
            m_mesh   = Mesh::IO::load(u);
        }
        mark();
        mesh(EMIT);
    }

    void        AMesh::on_set_mesh(const SetMeshCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        mesh(SET, cmd.mesh());
    }

    void        AMesh::on_set_mesh_spec(const SetMeshSpecCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
        mesh(SET, Resource::resolve(cmd.spec()));
    }
    
    void        AMesh::on_set_mesh_url(const SetMeshUrlCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        mesh(SET, cmd.url());
    }
}
