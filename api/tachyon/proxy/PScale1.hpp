////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <tachyon/interface/IScale1.hpp>

namespace yq::tachyon {
    class PScale¹ : public Proxy, public IScale¹  /* TODO: public public IScale */ {
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

        PScale¹(const IScale¹& i);
        ~PScale¹();

    private:
        const Vector1D  m_scale;
    };
}

