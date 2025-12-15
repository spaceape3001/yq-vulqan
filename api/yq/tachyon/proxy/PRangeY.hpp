////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeY.hpp>

namespace yq::tachyon {
    class PRangeʸ : public Proxy, public IRangeʸ {
    public:
    
        //!  Basic y_range in the 4I space
        RangeD      y_range() const { return m_yRange; }
        
        //!  Set y_range the y_range
        void        y_range(set_k, const RangeD&) override;
        
        bool        y_range(disabled_k) const override;
        bool        y_range(settable_k) const override;
        
        const RangeD&   y_range(ref_k) const { return m_yRange; }

        PRangeʸ(const IRangeʸ& i);
        virtual ~PRangeʸ();

    private:
        RangeD        m_yRange;
    };
}

