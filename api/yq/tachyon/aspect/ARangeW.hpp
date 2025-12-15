////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IRangeW.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetRangeʷCommand;
    class SetRangeˣCommand;
    class SetRangeʸCommand;
    class SetRangeᶻCommand;

    class ARangeʷ : public IRangeʷ, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            RangeD      w_range;
        };

        //!  Basic w_range in the 4D space
        RangeD          w_range() const override { return m_wRange; }
        
        //!  Set w_range the w_range (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    w_range(set_k, const RangeD&) override;
        
        bool            w_range(disabled_k) const { return false; }
        bool            w_range(settable_k) const { return true; }
        
        const RangeD&   w_range(ref_k) const { return m_wRange; }

    protected:

        RangeD          m_wRange;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARangeʷ(const Param&p);
        ARangeʷ(const RangeD& r=ZERO);
        virtual ~ARangeʷ();
        
        void        w_range(emit_k);
        
    private:
        void        on_set_w_range(const SetRangeʷCommand&);
    };

}
