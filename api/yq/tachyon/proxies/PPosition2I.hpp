////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2I.hpp>

namespace yq::tachyon {
    class PPosition2I : public Proxy, public IPosition2I {
    public:
    
        Vector2I    position2i() const override {  return m_position;  }
        
        void        position2i(set_t, const Vector2I&) override;
        void        position2i(move_t, const Vector2I&) override;

        PPosition2I(const IPosition2I& i);

    private:
        Vector2I        m_position;
    };
}

