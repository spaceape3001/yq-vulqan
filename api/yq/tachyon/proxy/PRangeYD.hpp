////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeYD.hpp>

namespace yq::tachyon {
    class PRangeʸD : public Proxy, public IRangeʸD {
    public:
    
        //!  Basic y_range in the 4I space
        RangeD      y_range() const { return m_yRange; }
        
        //!  Set y_range the y_range
        void        y_range(set_k, const RangeD&) override;
        
        bool        y_range(disabled_k) const override;
        bool        y_range(settable_k) const override;
        
        const RangeD&   y_range(ref_k) const { return m_yRange; }

        PRangeʸD(const IRangeʸD& i);
        virtual ~PRangeʸD();

    private:
        RangeD        m_yRange;
    };
}

