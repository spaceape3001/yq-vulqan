////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMeshEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/asset/Mesh.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMeshEvent)

namespace yq::tachyon {

    SetMeshEvent::SetMeshEvent(const Header&h, const MeshCPtr& dm, const Url& u) : ShapeEvent(h), m_mesh(dm), m_url(u)
    {
    }

    SetMeshEvent::SetMeshEvent(const SetMeshEvent& cp, const Header& h) : 
        ShapeEvent(cp, h), m_mesh(cp.m_mesh), m_url(cp.m_url)
    {
    }
    
    SetMeshEvent::~SetMeshEvent()
    {
    }

    PostCPtr    SetMeshEvent::clone(rebind_k, const Header&h) const 
    {
        return new SetMeshEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMeshEvent::init_meta()
    {
        auto w = writer<SetMeshEvent>();
        w.description("Set Mesh Event");
        w.property("url", &SetMeshEvent::m_url);
    }
}
