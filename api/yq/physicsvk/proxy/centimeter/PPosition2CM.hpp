////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/centimeter/IPosition2CM.hpp>

namespace yq::tachyon {
    class PPosition²CM : public Proxy, public IPosition²CM  /* TODO: public IPosition²CMI, public IPosition²CM, public IPosition */ {
    public:
    
        Centimeter2D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Centimeter2D&) override;
        void        position(set_k, x_k, Centimeter) override;
        void        position(set_k, y_k, Centimeter) override;
        
        void        position(add_k, const Centimeter2D&Δ) override;
        void        position(add_k, x_k, Centimeter Δx) override;
        void        position(add_k, y_k, Centimeter Δy) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector2D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;

        const Centimeter2D&  position(ref_k) const {  return m_position;  }

        Centimeter       x() const { return m_position.x; }
        Centimeter       y() const { return m_position.y; }

        PPosition²CM(const IPosition²CM& i);

    private:
        const Centimeter2D  m_position;
    };
}

