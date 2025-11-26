////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMaterial.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetMaterialCommand;

    class AMaterial : public IMaterial, public virtual Tachyon::Helper {
    public:
    
        MaterialCPtr        material() const override;
        virtual void        material(set_k, const MaterialCPtr&) override;

        bool                material(disabled_k) const { return false; }
        bool                material(settable_k) const { return true; }

        const MaterialCPtr& material(ref_k) const { return m_material; }

    protected:
        MaterialCPtr        m_material;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaterial();
        virtual ~AMaterial();

        void        material(emit_k);
        
    private:
        void        on_set_material(const SetMaterialCommand&);
    };

}
