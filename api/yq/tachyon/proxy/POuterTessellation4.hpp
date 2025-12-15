////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IOuterTessellation4.hpp>

namespace yq::tachyon {
    class POuterTessellation⁴ : public Proxy, public IOuterTessellation⁴ {
    public:
    
        Vector4D    outer_tessellation() const override {  return m_outerTessellation;  }
        bool        outer_tessellation(disabled_k) const override;
        bool        outer_tessellation(settable_k) const override;
        
        void        outer_tessellation(set_k, const Vector4D&) override;

        const Vector4D&  outer_tessellation(ref_k) const {  return m_outerTessellation;  }

        POuterTessellation⁴(const IOuterTessellation⁴& i);

    private:
        Vector4D    m_outerTessellation;
    };
}

