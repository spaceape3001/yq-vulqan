////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeZD.hpp>

namespace yq::tachyon {
    class PRangeᶻD : public Proxy, public IRangeᶻD {
    public:
    
        //!  Basic z_range in the 4I space
        RangeD      z_range() const { return m_zRange; }
        
        //!  Set z_range the z_range
        void        z_range(set_k, const RangeD&) override;
        
        bool        z_range(disabled_k) const override;
        bool        z_range(settable_k) const override;
        
        const RangeD&   z_range(ref_k) const { return m_zRange; }

        PRangeᶻD(const IRangeᶻD& i);
        virtual ~PRangeᶻD();

    private:
        RangeD        m_zRange;
    };
}

