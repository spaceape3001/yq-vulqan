////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IOuterTessellation3.hpp>

namespace yq::tachyon {
    class POuterTessellation³ : public Proxy, public IOuterTessellation³ {
    public:
    
        Vector3D    outer_tessellation() const override {  return m_outerTessellation;  }
        bool        outer_tessellation(disabled_k) const override;
        bool        outer_tessellation(settable_k) const override;
        
        void        outer_tessellation(set_k, const Vector3D&) override;

        const Vector3D&  outer_tessellation(ref_k) const {  return m_outerTessellation;  }

        POuterTessellation³(const IOuterTessellation³& i);

    private:
        Vector3D    m_outerTessellation;
    };
}

