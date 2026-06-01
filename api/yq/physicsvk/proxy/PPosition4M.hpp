////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/IPosition4M.hpp>

namespace yq::tachyon {
    class PPosition⁴M : public Proxy, public IPosition⁴M  /* TODO: public IPosition⁴MI, public IPosition⁴M, public IPosition */ {
    public:
    
        Meter4D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Meter4D&) override;
        void        position(set_k, x_k, Meter) override;
        void        position(set_k, y_k, Meter) override;
        void        position(set_k, z_k, Meter) override;
        void        position(set_k, w_k, Meter) override;

        void        position(add_k, const Meter4D&Δ) override;
        void        position(add_k, x_k, Meter Δx) override;
        void        position(add_k, y_k, Meter Δy) override;
        void        position(add_k, z_k, Meter Δz) override;
        void        position(add_k, w_k, Meter Δw) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector4D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;
        void        position(multiply_k, z_k, double Δz) override;
        void        position(multiply_k, w_k, double Δw) override;

        Meter       x() const { return m_position.x; }
        Meter       y() const { return m_position.y; }
        Meter       z() const { return m_position.z; }
        Meter       w() const { return m_position.w; }

        const Meter4D&  position(ref_k) const {  return m_position;  }

        PPosition⁴M(const IPosition⁴M& i);
        ~PPosition⁴M();

    private:
        const Meter4D  m_position;
    };
}

