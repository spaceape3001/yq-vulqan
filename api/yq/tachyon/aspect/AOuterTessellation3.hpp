////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IOuterTessellation3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetOuterTessellation³Command;

    class AOuterTessellation³ : public IOuterTessellation³, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector3D    outer_tessellation = ONE;
        };
    
        //!  Basic outer_tessellation in the 3D space
        Vector3D        outer_tessellation() const override { return m_outerTessellation; }

        //!  Set outer_tessellation the outer_tessellation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    outer_tessellation(set_k, const Vector3D&) override;

        bool            outer_tessellation(disabled_k) const { return false; }
        bool            outer_tessellation(settable_k) const { return true; }

        const Vector3D& outer_tessellation(ref_k) const { return m_outerTessellation; }

    protected:
        
        Vector3D    m_outerTessellation;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AOuterTessellation³(const Param&);
        AOuterTessellation³(const Vector3D& it=ONE);
        
        virtual ~AOuterTessellation³();

        void            outer_tessellation(emit_k);
        
    private:
        void        on_set_outer_tessellation3(const SetOuterTessellation³Command&);
    };

}
