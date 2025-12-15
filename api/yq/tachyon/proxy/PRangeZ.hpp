////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeZ.hpp>

namespace yq::tachyon {
    class PRangeᶻ : public Proxy, public IRangeᶻ {
    public:
    
        //!  Basic z_range in the 4I space
        RangeD      z_range() const { return m_zRange; }
        
        //!  Set z_range the z_range
        void        z_range(set_k, const RangeD&) override;
        
        bool        z_range(disabled_k) const override;
        bool        z_range(settable_k) const override;
        
        const RangeD&   z_range(ref_k) const { return m_zRange; }

        PRangeᶻ(const IRangeᶻ& i);
        virtual ~PRangeᶻ();

    private:
        RangeD        m_zRange;
    };
}

