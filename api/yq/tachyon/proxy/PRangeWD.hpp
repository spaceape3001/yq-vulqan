////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeWD.hpp>

namespace yq::tachyon {
    class PRangeʷD : public Proxy, public IRangeʷD {
    public:
    
        //!  Basic w_range in the 4I space
        RangeD      w_range() const { return m_wRange; }
        
        //!  Set w_range the w_range
        void        w_range(set_k, const RangeD&) override;
        
        bool        w_range(disabled_k) const override;
        bool        w_range(settable_k) const override;
        
        const RangeD&   w_range(ref_k) const { return m_wRange; }

        PRangeʷD(const IRangeʷD& i);
        virtual ~PRangeʷD();

    private:
        RangeD        m_wRange;
    };
}

