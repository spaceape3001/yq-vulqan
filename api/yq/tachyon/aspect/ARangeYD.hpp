////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IRangeYD.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetRangeʸDCommand;

    class ARangeʸD : public IRangeʸD, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            RangeD      y_range;
        };

        //!  Basic y_range in the 4D space
        RangeD          y_range() const override { return m_yRange; }
        
        //!  Set y_range the y_range (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    y_range(set_k, const RangeD&) override;
        
        bool            y_range(disabled_k) const { return false; }
        bool            y_range(settable_k) const { return true; }
        
        const RangeD&   y_range(ref_k) const { return m_yRange; }

    protected:

        RangeD          m_yRange;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARangeʸD(const Param&);
        ARangeʸD(const RangeD& rng=ZERO);
        virtual ~ARangeʸD();
        
        void        y_range(emit_k);
        
    private:
        void        on_set_y_range(const SetRangeʸDCommand&);
    };

}
