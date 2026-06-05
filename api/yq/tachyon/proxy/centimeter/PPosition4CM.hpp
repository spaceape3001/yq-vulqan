////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/centimeter/IPosition4CM.hpp>

namespace yq::tachyon {
    class PPosition⁴CM : public Proxy, public IPosition⁴CM  /* TODO: public IPosition⁴CMI, public IPosition⁴CM, public IPosition */ {
    public:
    
        Centimeter4D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Centimeter4D&) override;
        void        position(set_k, x_k, Centimeter) override;
        void        position(set_k, y_k, Centimeter) override;
        void        position(set_k, z_k, Centimeter) override;
        void        position(set_k, w_k, Centimeter) override;

        void        position(add_k, const Centimeter4D&Δ) override;
        void        position(add_k, x_k, Centimeter Δx) override;
        void        position(add_k, y_k, Centimeter Δy) override;
        void        position(add_k, z_k, Centimeter Δz) override;
        void        position(add_k, w_k, Centimeter Δw) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector4D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;
        void        position(multiply_k, z_k, double Δz) override;
        void        position(multiply_k, w_k, double Δw) override;

        Centimeter       x() const { return m_position.x; }
        Centimeter       y() const { return m_position.y; }
        Centimeter       z() const { return m_position.z; }
        Centimeter       w() const { return m_position.w; }

        const Centimeter4D&  position(ref_k) const {  return m_position;  }

        PPosition⁴CM(const IPosition⁴CM& i);
        ~PPosition⁴CM();

    private:
        const Centimeter4D  m_position;
    };
}

