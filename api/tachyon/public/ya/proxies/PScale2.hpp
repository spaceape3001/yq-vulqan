////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/IScale2.hpp>

namespace yq::tachyon {
    class PScale² : public Proxy, public IScale²  /* TODO: public public IScale */ {
    public:
        Vector2D    scale() const override {  return m_scale;  }
        bool        scale(disabled_k) const override;
        bool        scale(settable_k) const override;
        bool        scale(addable_k) const override;
        bool        scale(multipliable_k) const override;
        
        void        scale(set_k, const Vector2D&) override;
        void        scale(set_k, x_k, double) override;
        void        scale(set_k, y_k, double) override;

        void        scale(add_k, const Vector2D&Δ) override;
        void        scale(add_k, x_k, double Δx) override;
        void        scale(add_k, y_k, double Δy) override;

        void        scale(multiply_k, double) override;
        void        scale(multiply_k, const Vector2D&Δ) override;
        void        scale(multiply_k, x_k, double Δx) override;
        void        scale(multiply_k, y_k, double Δy) override;

        double      x() const { return m_scale.x; }
        double      y() const { return m_scale.y; }

        const Vector2D&  scale(ref_k) const {  return m_scale;  }

        PScale²(const IScale²& i);
        ~PScale²();

    private:
        const Vector2D  m_scale;
    };
}

