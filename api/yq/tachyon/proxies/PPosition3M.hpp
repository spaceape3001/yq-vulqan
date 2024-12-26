////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3M.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class PPosition3M : public Proxy, public IPosition3M  /* TODO: public IPosition3D, public IPosition3I, public IPosition3, public IPosition */  {
    public:
    
        Vector3M    position3m() const override {  return m_position;  }
        bool        position3m(disabled_t) const override;
        bool        position3m(settable_t) const override;
        bool        position3m(adjustable_t) const override;
        
        void        position3m(set_k, const Vector3M&) override;
        void        position3m(adjust_t, const Vector3M&) override;

        PPosition3M(const IPosition3M& i);

    private:
        Vector3M        m_position;
    };
}

