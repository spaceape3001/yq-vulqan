////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2.hpp>

namespace yq::tachyon {
    class PPosition2 : public Proxy, public IPosition2  /* TODO: public IPosition2I, public IPosition2, public IPosition */ {
    public:
    
        Vector2D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(moveable_k) const override;
        
        void        position(set_k, const Vector2D&) override;
        void        position(set_k, x_k, double) override;
        void        position(set_k, y_k, double) override;
        void        position(move_k, const Vector2D&Δ) override;
        void        position(move_k, x_k, double Δx) override;
        void        position(move_k, y_k, double Δy) override;

        const Vector2D&  position(ref_k) const {  return m_position;  }

        double      x() const { return m_position.x; }
        double      y() const { return m_position.y; }

        PPosition2(const IPosition2& i);

    private:
        const Vector2D  m_position;
    };
}

