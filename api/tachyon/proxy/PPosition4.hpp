////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/IPosition4.hpp>

namespace yq::tachyon {
    class PPosition⁴ : public Proxy, public IPosition⁴  /* TODO: public IPosition⁴I, public IPosition⁴, public IPosition */ {
    public:
    
        Vector4D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Vector4D&) override;
        void        position(set_k, x_k, double) override;
        void        position(set_k, y_k, double) override;
        void        position(set_k, z_k, double) override;
        void        position(set_k, w_k, double) override;

        void        position(add_k, const Vector4D&Δ) override;
        void        position(add_k, x_k, double Δx) override;
        void        position(add_k, y_k, double Δy) override;
        void        position(add_k, z_k, double Δz) override;
        void        position(add_k, w_k, double Δw) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector4D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;
        void        position(multiply_k, z_k, double Δz) override;
        void        position(multiply_k, w_k, double Δw) override;

        double      x() const { return m_position.x; }
        double      y() const { return m_position.y; }
        double      z() const { return m_position.z; }
        double      w() const { return m_position.w; }

        const Vector4D&  position(ref_k) const {  return m_position;  }

        PPosition⁴(const IPosition⁴& i);
        ~PPosition⁴();

    private:
        const Vector4D  m_position;
    };
}

