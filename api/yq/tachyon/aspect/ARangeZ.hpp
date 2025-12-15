////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IRangeZ.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetRangeᶻCommand;

    class ARangeᶻ : public IRangeᶻ, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            RangeD      z_range;
        };
    
        //!  Basic z_range in the 4D space
        RangeD          z_range() const override { return m_zRange; }
        
        //!  Set z_range the z_range (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    z_range(set_k, const RangeD&) override;
        
        bool            z_range(disabled_k) const { return false; }
        bool            z_range(settable_k) const { return true; }
        
        const RangeD&   z_range(ref_k) const { return m_zRange; }

    protected:

        RangeD          m_zRange;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARangeᶻ(const Param&);
        ARangeᶻ(const RangeD& r=ZERO);
        virtual ~ARangeᶻ();
        
        void        z_range(emit_k);
        
    private:
        void        on_set_z_range(const SetRangeᶻCommand&);
    };

}
