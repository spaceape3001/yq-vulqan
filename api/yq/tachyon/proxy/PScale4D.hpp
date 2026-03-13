////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IScale4D.hpp>

namespace yq::tachyon {
    class PScale⁴D : public Proxy, public IScale⁴D  /* TODO: public public IScale */ {
    public:
        Vector4D    scale() const override {  return m_scale;  }
        bool        scale(disabled_k) const override;
        bool        scale(settable_k) const override;
        bool        scale(addable_k) const override;
        bool        scale(multipliable_k) const override;
        
        void        scale(set_k, const Vector4D&) override;
        void        scale(set_k, x_k, double) override;
        void        scale(set_k, y_k, double) override;
        void        scale(set_k, z_k, double) override;
        void        scale(set_k, w_k, double) override;

        void        scale(add_k, const Vector4D&Δ) override;
        void        scale(add_k, x_k, double Δx) override;
        void        scale(add_k, y_k, double Δy) override;
        void        scale(add_k, z_k, double Δz) override;
        void        scale(add_k, w_k, double Δw) override;

        void        scale(multiply_k, double) override;
        void        scale(multiply_k, const Vector4D&Δ) override;
        void        scale(multiply_k, x_k, double Δx) override;
        void        scale(multiply_k, y_k, double Δy) override;
        void        scale(multiply_k, z_k, double Δz) override;
        void        scale(multiply_k, w_k, double Δw) override;

        double      w() const { return m_scale.w; }
        double      x() const { return m_scale.x; }
        double      y() const { return m_scale.y; }
        double      z() const { return m_scale.z; }

        const Vector4D&  scale(ref_k) const {  return m_scale;  }

        PScale⁴D(const IScale⁴D& i);
        ~PScale⁴D();

    private:
        const Vector4D  m_scale;
    };
}

