////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3.hpp>

namespace yq::tachyon {
    class PPosition³ : public Proxy, public IPosition³  /* TODO: public IPosition³I, public IPosition³, public IPosition */ {
    public:
    
        Vector3D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(moveable_k) const override;
        
        void        position(set_k, const Vector3D&) override;
        void        position(set_k, x_k, double) override;
        void        position(set_k, y_k, double) override;
        void        position(set_k, z_k, double) override;
        void        position(move_k, const Vector3D&Δ) override;
        void        position(move_k, x_k, double Δx) override;
        void        position(move_k, y_k, double Δy) override;
        void        position(move_k, z_k, double Δz) override;

        double      x() const { return m_position.x; }
        double      y() const { return m_position.y; }
        double      z() const { return m_position.z; }

        const Vector3D&  position(ref_k) const {  return m_position;  }

        PPosition³(const IPosition³& i);
        ~PPosition³();

    private:
        const Vector3D  m_position;
    };
}

