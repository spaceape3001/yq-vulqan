////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2D.hpp>

namespace yq::tachyon {
    class PPosition2D : public Proxy, public IPosition2D {
    public:
    
        Vector2D    position2d() const override {  return m_position;  }
        
        void        position2d(set_t, const Vector2D&) override;
        void        position2d(move_t, const Vector2D&) override;

    private:
        PPosition2D(IPosition2D& i);

        IPosition2D&    m_interface;
        Vector2D        m_position;
    };
}

