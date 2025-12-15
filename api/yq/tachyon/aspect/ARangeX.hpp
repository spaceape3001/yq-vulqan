////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IRangeX.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetRangeˣCommand;

    class ARangeˣ : public IRangeˣ, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            RangeD      x_range;
        };

        //!  Basic x_range in the 4D space
        RangeD          x_range() const override { return m_xRange; }
        
        //!  Set x_range the x_range (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    x_range(set_k, const RangeD&) override;
        
        bool            x_range(disabled_k) const { return false; }
        bool            x_range(settable_k) const { return true; }
        
        const RangeD&   x_range(ref_k) const { return m_xRange; }

    protected:

        RangeD          m_xRange;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARangeˣ(const Param&);
        ARangeˣ(const RangeD& r=ZERO);
        virtual ~ARangeˣ();
        
        void        x_range(emit_k);
        
    private:
        void        on_set_x_range(const SetRangeˣCommand&);
    };

}
