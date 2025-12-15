////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IInnerTessellation2.hpp>

namespace yq::tachyon {
    class PInnerTessellation² : public Proxy, public IInnerTessellation² {
    public:
    
        Vector2D    inner_tessellation() const override {  return m_innerTessellation;  }
        bool        inner_tessellation(disabled_k) const override;
        bool        inner_tessellation(settable_k) const override;
        
        void        inner_tessellation(set_k, const Vector2D&) override;

        const Vector2D&  inner_tessellation(ref_k) const {  return m_innerTessellation;  }

        PInnerTessellation²(const IInnerTessellation²& i);

    private:
        Vector2D    m_innerTessellation;
    };
}

