////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IRangeY.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetRangeʸCommand;

    class ARangeʸ : public IRangeʸ, public virtual Tachyon::Helper {
    public:
    
        //!  Basic y_range in the 4D space
        RangeD          y_range() const override { return m_yRange; }
        
        //!  Set y_range the y_range (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    y_range(set_k, const RangeD&) override;
        
        bool            y_range(disabled_k) const { return false; }
        bool            y_range(settable_k) const { return true; }
        
        const RangeD&   y_range(ref_k) const { return m_yRange; }

    protected:

        RangeD          m_yRange = ZERO;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARangeʸ();
        virtual ~ARangeʸ();
        
        void        y_range(emit_k);
        
    private:
        void        on_set_y_range(const SetRangeʸCommand&);
    };

}
