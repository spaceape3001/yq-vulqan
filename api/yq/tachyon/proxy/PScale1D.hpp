////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IScale1D.hpp>

namespace yq::tachyon {
    class PScale¹D : public Proxy, public IScale¹D  /* TODO: public public IScale */ {
    public:
        Vector1D    scale() const override {  return m_scale;  }
        bool        scale(disabled_k) const override;
        bool        scale(settable_k) const override;
        bool        scale(addable_k) const override;
        bool        scale(multipliable_k) const override;
        
        void        scale(set_k, const Vector1D&) override;
        void        scale(set_k, x_k, double) override;

        void        scale(add_k, const Vector1D&Δ) override;
        void        scale(add_k, x_k, double Δx) override;

        void        scale(multiply_k, double) override;
        void        scale(multiply_k, const Vector1D&Δ) override;
        void        scale(multiply_k, x_k, double Δx) override;

        double      x() const { return m_scale.x; }

        const Vector1D&  scale(ref_k) const {  return m_scale;  }

        PScale¹D(const IScale¹D& i);
        ~PScale¹D();

    private:
        const Vector1D  m_scale;
    };
}

