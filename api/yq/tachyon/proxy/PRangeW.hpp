////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeW.hpp>

namespace yq::tachyon {
    class PRangeʷ : public Proxy, public IRangeʷ {
    public:
    
        //!  Basic w_range in the 4I space
        RangeD      w_range() const { return m_wRange; }
        
        //!  Set w_range the w_range
        void        w_range(set_k, const RangeD&) override;
        
        bool        w_range(disabled_k) const override;
        bool        w_range(settable_k) const override;
        
        const RangeD&   w_range(ref_k) const { return m_wRange; }

        PRangeʷ(const IRangeʷ& i);
        virtual ~PRangeʷ();

    private:
        RangeD        m_wRange;
    };
}

