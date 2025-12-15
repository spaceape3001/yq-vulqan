////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IOuterTessellation4.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetOuterTessellation⁴Command;

    class AOuterTessellation⁴ : public IOuterTessellation⁴, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector4D    outer_tessellation = ONE;
        };
    
        //!  Basic outer_tessellation in the 4D space
        Vector4D        outer_tessellation() const override { return m_outerTessellation; }
        
        //!  Set outer_tessellation the outer_tessellation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    outer_tessellation(set_k, const Vector4D&) override;

        bool            outer_tessellation(disabled_k) const { return false; }
        bool            outer_tessellation(settable_k) const { return true; }

        const Vector4D& outer_tessellation(ref_k) const { return m_outerTessellation; }

    protected:
        
        Vector4D    m_outerTessellation;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AOuterTessellation⁴(const Param&);
        AOuterTessellation⁴(const Vector4D& it=ONE);
        
        virtual ~AOuterTessellation⁴();

        void            outer_tessellation(emit_k);
        
    private:
        void        on_set_outer_tessellation4(const SetOuterTessellation⁴Command&);
    };

}
