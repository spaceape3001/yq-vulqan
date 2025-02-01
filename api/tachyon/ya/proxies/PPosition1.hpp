////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/IPosition1.hpp>

namespace yq::tachyon {
    class PPosition¹ : public Proxy, public IPosition¹  /* TODO: public IPosition¹I, public IPosition¹, public IPosition */  {
    public:
    
        Vector1D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Vector1D&) override;
        void        position(set_k, x_k, double) override;
        
        void        position(add_k, const Vector1D&Δ) override;
        void        position(add_k, x_k, double Δx) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector1D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;

        const Vector1D&  position(ref_k) const {  return m_position;  }

        double      x() const { return m_position.x; }

        PPosition¹(const IPosition¹& i);

    private:
        Vector1D        m_position;
    };
}

