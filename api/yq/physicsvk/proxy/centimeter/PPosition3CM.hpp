////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/centimeter/IPosition3CM.hpp>

namespace yq::tachyon {
    class PPosition³CM : public Proxy, public IPosition³CM  /* TODO: public IPosition³CMI, public IPosition³CM, public IPosition */ {
    public:
    
        Centimeter3D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Centimeter3D&) override;
        void        position(set_k, x_k, Centimeter) override;
        void        position(set_k, y_k, Centimeter) override;
        void        position(set_k, z_k, Centimeter) override;

        void        position(add_k, const Centimeter3D&Δ) override;
        void        position(add_k, x_k, Centimeter Δx) override;
        void        position(add_k, y_k, Centimeter Δy) override;
        void        position(add_k, z_k, Centimeter Δz) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector3D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;
        void        position(multiply_k, z_k, double Δz) override;

        Centimeter       x() const { return m_position.x; }
        Centimeter       y() const { return m_position.y; }
        Centimeter       z() const { return m_position.z; }

        const Centimeter3D&  position(ref_k) const {  return m_position;  }

        PPosition³CM(const IPosition³CM& i);
        ~PPosition³CM();

    private:
        const Centimeter3D  m_position;
    };
}

