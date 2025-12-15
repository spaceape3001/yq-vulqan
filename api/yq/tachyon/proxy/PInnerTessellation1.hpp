////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IInnerTessellation1.hpp>

namespace yq::tachyon {
    class PInnerTessellation¹ : public Proxy, public IInnerTessellation¹ {
    public:
    
        Vector1D    inner_tessellation() const override {  return m_innerTessellation;  }
        bool        inner_tessellation(disabled_k) const override;
        bool        inner_tessellation(settable_k) const override;
        
        void        inner_tessellation(set_k, const Vector1D&) override;

        const Vector1D&  inner_tessellation(ref_k) const {  return m_innerTessellation;  }

        PInnerTessellation¹(const IInnerTessellation¹& i);

    private:
        Vector1D    m_innerTessellation;
    };
}

