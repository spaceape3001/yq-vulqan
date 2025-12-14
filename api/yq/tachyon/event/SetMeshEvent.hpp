////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/mesh.hpp>

namespace yq::tachyon {
    class SetMeshEvent : public Event {
        YQ_OBJECT_DECLARE(SetMeshEvent, Event)
    public:
        SetMeshEvent(const Header&, const MeshCPtr&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&          url() const { return m_url; }
        const MeshCPtr&     mesh() const { return m_mesh; }

    protected:
        SetMeshEvent(const SetMeshEvent&, const Header&);
        virtual ~SetMeshEvent();
        
    private:
    
        MeshCPtr     m_mesh;
        Url          m_url;

        SetMeshEvent(const SetMeshEvent&) = delete;
        SetMeshEvent(SetMeshEvent&&) = delete;
        SetMeshEvent& operator=(const SetMeshEvent&) = delete;
        SetMeshEvent& operator=(SetMeshEvent&&) = delete;
    };
}
