////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/IScale3.hpp>

namespace yq::tachyon {
    class PScale³ : public Proxy, public IScale³  /* TODO: public public IScale */ {
    public:
        Vector3D    scale() const override {  return m_scale;  }
        bool        scale(disabled_k) const override;
        bool        scale(settable_k) const override;
        bool        scale(addable_k) const override;
        bool        scale(multipliable_k) const override;
        
        void        scale(set_k, const Vector3D&) override;
        void        scale(set_k, x_k, double) override;
        void        scale(set_k, y_k, double) override;
        void        scale(set_k, z_k, double) override;

        void        scale(add_k, const Vector3D&Δ) override;
        void        scale(add_k, x_k, double Δx) override;
        void        scale(add_k, y_k, double Δy) override;
        void        scale(add_k, z_k, double Δz) override;

        void        scale(multiply_k, const Vector3D&Δ) override;
        void        scale(multiply_k, x_k, double Δx) override;
        void        scale(multiply_k, y_k, double Δy) override;
        void        scale(multiply_k, z_k, double Δz) override;

        double      x() const { return m_scale.x; }
        double      y() const { return m_scale.y; }
        double      z() const { return m_scale.z; }

        const Vector3D&  scale(ref_k) const {  return m_scale;  }

        PScale³(const IScale³& i);
        ~PScale³();

    private:
        const Vector3D  m_scale;
    };
}

