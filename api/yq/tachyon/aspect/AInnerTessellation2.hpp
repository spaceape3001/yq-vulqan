////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IInnerTessellation2.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetInnerTessellation²Command;

    class AInnerTessellation² : public IInnerTessellation², public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector2D    inner_tessellation = ZERO;
        };
    
        //!  Basic inner_tessellation in the 2D space
        Vector2D        inner_tessellation() const override { return m_innerTessellation; }

        //!  Set inner_tessellation the inner_tessellation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    inner_tessellation(set_k, const Vector2D&) override;

        bool            inner_tessellation(disabled_k) const { return false; }
        bool            inner_tessellation(settable_k) const { return true; }

        const Vector2D& inner_tessellation(ref_k) const { return m_innerTessellation; }

    protected:
        
        Vector2D    m_innerTessellation;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AInnerTessellation²(const Param&);
        AInnerTessellation²(const Vector2D& it=ZERO);
        
        virtual ~AInnerTessellation²();

        void            inner_tessellation(emit_k);
        
    private:
        void        on_set_inner_tessellation2(const SetInnerTessellation²Command&);
    };

}
