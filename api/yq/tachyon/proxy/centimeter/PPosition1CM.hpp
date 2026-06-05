////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/centimeter/IPosition1CM.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {
    class PPosition¹CM : public Proxy, public IPosition¹CM  /* TODO: public IPosition¹CMI, public IPosition¹CM, public IPosition */  {
    public:
    
        Centimeter1D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Centimeter1D&) override;
        void        position(set_k, x_k, Centimeter) override;
        
        void        position(add_k, const Centimeter1D&Δ) override;
        void        position(add_k, x_k, Centimeter Δx) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector1D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;

        const Centimeter1D&  position(ref_k) const {  return m_position;  }

        Centimeter       x() const { return m_position.x; }

        PPosition¹CM(const IPosition¹CM& i);

    private:
        const Centimeter1D  m_position;
    };
}

