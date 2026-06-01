////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/IPosition3M.hpp>

namespace yq::tachyon {
    class PPosition³M : public Proxy, public IPosition³M  /* TODO: public IPosition³MI, public IPosition³M, public IPosition */ {
    public:
    
        Meter3D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Meter3D&) override;
        void        position(set_k, x_k, Meter) override;
        void        position(set_k, y_k, Meter) override;
        void        position(set_k, z_k, Meter) override;

        void        position(add_k, const Meter3D&Δ) override;
        void        position(add_k, x_k, Meter Δx) override;
        void        position(add_k, y_k, Meter Δy) override;
        void        position(add_k, z_k, Meter Δz) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector3D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;
        void        position(multiply_k, z_k, double Δz) override;

        Meter       x() const { return m_position.x; }
        Meter       y() const { return m_position.y; }
        Meter       z() const { return m_position.z; }

        const Meter3D&  position(ref_k) const {  return m_position;  }

        PPosition³M(const IPosition³M& i);
        ~PPosition³M();

    private:
        const Meter3D  m_position;
    };
}

