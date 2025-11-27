////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMesh.hpp"
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/command/shape/SetMeshCommand.hpp>
#include <yq/tachyon/command/shape/SetMeshUrlCommand.hpp>

namespace yq::tachyon {
    PMesh::PMesh(const IMesh& i) : m_mesh(i.mesh()), m_url(i.mesh(URL))
    {
        if(i.mesh(DISABLED))
            m_flags |= F::Disabled;
        if(i.mesh(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PMesh::~PMesh()
    {
    }

    MeshCPtr    PMesh::mesh() const
    {
        return m_mesh;
    }
    
    Url     PMesh::mesh(url_k) const
    {
        return m_url;
    }
    
    void    PMesh::mesh(set_k, const MeshCPtr& tex) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMeshCommand({.target=object()}, tex));
        }
    }
    
    void    PMesh::mesh(set_k, const Url& u)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMeshUrlCommand({.target=object()}, u));
        }
    }
    
    bool    PMesh::mesh(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool    PMesh::mesh(settable_k) const 
    {
        return m_flags(F::Settable);
    }
}
