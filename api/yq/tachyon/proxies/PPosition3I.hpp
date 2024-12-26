////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3I.hpp>

namespace yq::tachyon {
    class PPosition3I : public Proxy, public IPosition3I  /* TODO: public IPosition3D, public IPosition3, public IPosition */ {
    public:
    
        Vector3I    position3i() const override {  return m_position;  }
        bool        position3i(disabled_k) const override;
        bool        position3i(settable_k) const override;
        bool        position3i(adjustable_k) const override;
        
        void        position3i(set_k, const Vector3I&) override;
        void        position3i(adjust_k, const Vector3I&) override;

        PPosition3I(const IPosition3I& i);

    private:
        Vector3I        m_position;
    };
}

