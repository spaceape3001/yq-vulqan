////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4I.hpp>

namespace yq::tachyon {
    class PPosition4I : public Proxy, public IPosition4I {
    public:
    
        Vector4I    position4i() const override {  return m_position;  }
        
        void        position4i(set_t, const Vector4I&) override;
        void        position4i(move_t, const Vector4I&) override;

    private:
        PPosition4I(IPosition4I& i);

        IPosition4I&    m_interface;
        Vector4I        m_position;
    };
}

