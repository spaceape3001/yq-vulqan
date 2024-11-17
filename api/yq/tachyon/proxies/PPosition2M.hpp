////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2M.hpp>

namespace yq::tachyon {
    class PPosition2M : public Proxy, public IPosition2M {
    public:
    
        Vector2M    position2m() const override {  return m_position;  }
        
        void        position2m(set_t, const Vector2M&) override;
        void        position2m(move_t, const Vector2M&) override;

    private:
        PPosition2M(IPosition2M& i);

        IPosition2M&    m_interface;
        Vector2M        m_position;
    };
}

