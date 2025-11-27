////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMesh.hpp>

namespace yq::tachyon {
    class PMesh : public Proxy, public IMesh {
    public:
    
        virtual MeshCPtr    mesh() const override;
        virtual Url         mesh(url_k) const override;
        virtual void        mesh(set_k, const MeshCPtr&) override;
        virtual void        mesh(set_k, const Url&) override;
        virtual bool        mesh(disabled_k) const override;
        virtual bool        mesh(settable_k) const override;


        PMesh(const IMesh&);
        virtual ~PMesh();
        
    private:
        MeshCPtr        m_mesh;
        Url             m_url;
    };
}
