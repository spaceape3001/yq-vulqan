////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRangeX.hpp>

namespace yq::tachyon {
    class PRangeˣ : public Proxy, public IRangeˣ {
    public:
    
        //!  Basic x_range in the 4I space
        RangeD      x_range() const { return m_xRange; }
        
        //!  Set x_range the x_range
        void        x_range(set_k, const RangeD&) override;
        
        bool        x_range(disabled_k) const override;
        bool        x_range(settable_k) const override;
        
        const RangeD&   x_range(ref_k) const { return m_xRange; }

        PRangeˣ(const IRangeˣ& i);
        virtual ~PRangeˣ();

    private:
        RangeD        m_xRange;
    };
}

