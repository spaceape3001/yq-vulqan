////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMaterial.hpp>

namespace yq::tachyon {
    class PMaterial : public Proxy, public IMaterial {
    public:
    
        virtual MaterialCPtr    material() const override;
        virtual Url             material(url_k) const override;
        virtual void            material(set_k, const MaterialCPtr&) override;
        virtual void            material(set_k, const Url&) override;
        virtual bool            material(disabled_k) const override;
        virtual bool            material(settable_k) const override;


        PMaterial(const IMaterial&);
        virtual ~PMaterial();
        
    private:
        MaterialCPtr    m_material;
        Url             m_url;
    };
}
