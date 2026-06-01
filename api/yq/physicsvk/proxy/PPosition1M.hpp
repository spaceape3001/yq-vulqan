////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/IPosition1M.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {
    class PPosition¹M : public Proxy, public IPosition¹M  /* TODO: public IPosition¹MI, public IPosition¹M, public IPosition */  {
    public:
    
        Meter1D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Meter1D&) override;
        void        position(set_k, x_k, Meter) override;
        
        void        position(add_k, const Meter1D&Δ) override;
        void        position(add_k, x_k, Meter Δx) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector1D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;

        const Meter1D&  position(ref_k) const {  return m_position;  }

        Meter       x() const { return m_position.x; }

        PPosition¹M(const IPosition¹M& i);

    private:
        const Meter1D  m_position;
    };
}

