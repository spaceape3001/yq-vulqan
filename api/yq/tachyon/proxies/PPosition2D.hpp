////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2D.hpp>

namespace yq::tachyon {
    class PPosition2D : public Proxy, public IPosition2D  /* TODO: public IPosition2I, public IPosition2, public IPosition */ {
    public:
    
        Vector2D    position2d() const override {  return m_position;  }
        bool        position2d(disabled_k) const override;
        bool        position2d(settable_k) const override;
        bool        position2d(adjustable_k) const override;
        
        void        position2d(set_k, const Vector2D&) override;
        void        position2d(adjust_k, const Vector2D&) override;

        PPosition2D(const IPosition2D& i);

    private:
        Vector2D        m_position;
    };
}

