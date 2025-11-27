////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/interface/IMaterial.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetMaterialCommand;
    class SetMaterialUrlCommand;

    class AMaterial : public IMaterial, public virtual Tachyon::Helper {
    public:
    
        MaterialCPtr        material() const override;
        Url                 material(url_k) const override;
        virtual void        material(set_k, const MaterialCPtr&) override;
        virtual void        material(set_k, const Url&) override;

        bool                material(disabled_k) const { return false; }
        bool                material(settable_k) const { return true; }

        const MaterialCPtr& material(ref_k) const { return m_material; }

    protected:
        MaterialCPtr        m_material;
        Url                 m_materialUrl;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaterial();
        virtual ~AMaterial();

        virtual void    material(emit_k);
        
    private:
        void        on_set_material(const SetMaterialCommand&);
        void        on_set_material_url(const SetMaterialUrlCommand&);
    };

}
