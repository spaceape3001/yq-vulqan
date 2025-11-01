////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IPosition2.hpp>

namespace yq::tachyon {
    class PPosition² : public Proxy, public IPosition²  /* TODO: public IPosition²I, public IPosition², public IPosition */ {
    public:
    
        Vector2D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(addable_k) const override;
        bool        position(multipliable_k) const override;
        
        void        position(set_k, const Vector2D&) override;
        void        position(set_k, x_k, double) override;
        void        position(set_k, y_k, double) override;
        
        void        position(add_k, const Vector2D&Δ) override;
        void        position(add_k, x_k, double Δx) override;
        void        position(add_k, y_k, double Δy) override;

        void        position(multiply_k, double) override;
        void        position(multiply_k, const Vector2D&Δ) override;
        void        position(multiply_k, x_k, double Δx) override;
        void        position(multiply_k, y_k, double Δy) override;

        const Vector2D&  position(ref_k) const {  return m_position;  }

        double      x() const { return m_position.x; }
        double      y() const { return m_position.y; }

        PPosition²(const IPosition²& i);

    private:
        const Vector2D  m_position;
    };
}

