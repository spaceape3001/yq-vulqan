////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2I.hpp>

namespace yq::tachyon {
    class PPosition2I : public Proxy, public IPosition2I  /* TODO: public IPosition3D, public IPosition3, public IPosition */ {
    public:
    
        Vector2I    position2i() const override {  return m_position;  }
        bool        position2i(disabled_t) const override;
        bool        position2i(settable_t) const override;
        bool        position2i(adjustable_t) const override;
        
        void        position2i(set_k, const Vector2I&) override;
        void        position2i(adjust_t, const Vector2I&) override;

        PPosition2I(const IPosition2I& i);

    private:
        Vector2I        m_position;
    };
}

