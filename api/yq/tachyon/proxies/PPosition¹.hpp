////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1.hpp>

namespace yq::tachyon {
    class PPosition1 : public Proxy, public IPosition1  /* TODO: public IPosition1I, public IPosition1, public IPosition */  {
    public:
    
        Vector1D    position() const override {  return m_position;  }
        bool        position(disabled_k) const override;
        bool        position(settable_k) const override;
        bool        position(moveable_k) const override;
        
        void        position(set_k, const Vector1D&) override;
        void        position(set_k, x_k, double) override;
        void        position(move_k, const Vector1D&Δ) override;
        void        position(move_k, x_k, double Δx) override;

        const Vector1D&  position(ref_k) const {  return m_position;  }

        double      x() const { return m_position.x; }

        PPosition1(const IPosition1& i);

    private:
        Vector1D        m_position;
    };
}

