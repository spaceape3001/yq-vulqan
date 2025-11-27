////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/typedef/mesh.hpp>
#include <yq/typedef/url.hpp>

namespace yq::tachyon {
    class PMesh;
    
    class IMesh {
    public:
        YQ_INTERFACE_DECLARE(IMesh, PMesh)

        virtual MeshCPtr    mesh() const = 0;
        virtual Url         mesh(url_k) const = 0;
        virtual void        mesh(set_k, const MeshCPtr&){}
        virtual void        mesh(set_k, const Url&){}

        virtual bool        mesh(disabled_k) const { return false; }
        virtual bool        mesh(settable_k) const { return false; }

        static void init_meta();
    };
}
