////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IInnerTessellation1.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetInnerTessellation¹Command;

    class AInnerTessellation¹ : public IInnerTessellation¹, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector1D    inner_tessellation = ZERO;
        };
    
        //!  Basic inner_tessellation in the 1D space
        Vector1D        inner_tessellation() const override { return m_innerTessellation; }

        //!  Set inner_tessellation the inner_tessellation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    inner_tessellation(set_k, const Vector1D&) override;

        bool            inner_tessellation(disabled_k) const { return false; }
        bool            inner_tessellation(settable_k) const { return true; }

        const Vector1D& inner_tessellation(ref_k) const { return m_innerTessellation; }

    protected:
        
        Vector1D    m_innerTessellation;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AInnerTessellation¹(const Param&);
        AInnerTessellation¹(const Vector1D& it=ZERO);
        
        virtual ~AInnerTessellation¹();

        void            inner_tessellation(emit_k);
        
    private:
        void        on_set_inner_tessellation1(const SetInnerTessellation¹Command&);
    };

}
