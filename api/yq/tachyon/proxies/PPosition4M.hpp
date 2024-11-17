////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4M.hpp>

namespace yq::tachyon {
    class PPosition4M : public Proxy, public IPosition4M {
    public:
    
        Vector4M    position4m() const override {  return m_position;  }
        
        void        position4m(set_t, const Vector4M&) override;
        void        position4m(move_t, const Vector4M&) override;

    private:
        PPosition4M(IPosition4M& i);

        IPosition4M&    m_interface;
        Vector4M        m_position;
    };
}

