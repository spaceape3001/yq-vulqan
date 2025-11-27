////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/interface/IMesh.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetMeshCommand;
    class SetMeshUrlCommand;

    class AMesh : public IMesh, public virtual Tachyon::Helper {
    public:
    
        MeshCPtr            mesh() const override;
        Url                 mesh(url_k) const override;
        virtual void        mesh(set_k, const MeshCPtr&) override;
        virtual void        mesh(set_k, const Url&) override;

        bool                mesh(disabled_k) const { return false; }
        bool                mesh(settable_k) const { return true; }

        const MeshCPtr&     mesh(ref_k) const { return m_mesh; }

    protected:
        MeshCPtr            m_mesh;
        Url                 m_meshUrl;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMesh();
        virtual ~AMesh();

        virtual void    mesh(emit_k);
        
    private:
        void        on_set_mesh(const SetMeshCommand&);
        void        on_set_mesh_url(const SetMeshUrlCommand&);
    };

}
