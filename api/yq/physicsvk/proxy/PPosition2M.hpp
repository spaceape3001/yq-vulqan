////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/physicsvk/interface/IPosition2M.hpp>

namespace yq::tachyon {
    class PPosition²M : public Proxy, public IPosition²M  /* TODO: public IPosition²MI, public IPosition²M, public IPosition */ {
    public:
    
        Meter2D     position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Meter2D&) override;
        void        position(set_k, x_k, Meter) override;
        void        position(set_k, y_k, Meter) override;
        
        void        position(add_k, const Meter2D&Δ) override;
        void        position(add_k, x_k, Meter Δx) override;
        void        position(add_k, y_k, Meter Δy) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector2D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;

        const Meter2D&  position(ref_k) const {  return m_position;  }

        Meter       x() const { return m_position.x; }
        Meter       y() const { return m_position.y; }

        PPosition²M(const IPosition²M& i);

    private:
        const Meter2D  m_position;
    };
}

