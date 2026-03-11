////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IPosition1D.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {
    class PPosition¹D : public Proxy, public IPosition¹D  /* TODO: public IPosition¹DI, public IPosition¹D, public IPosition */  {
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

        PPosition¹D(const IPosition¹D& i);

    private:
        const Vector1D   m_position;
    };
}

