////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4D.hpp>

namespace yq::tachyon {
    class PPosition4D : public Proxy, public IPosition4D {
    public:
    
        Vector4D    position4d() const override {  return m_position;  }
        
        void        position4d(set_t, const Vector4D&) override;
        void        position4d(move_t, const Vector4D&) override;

    private:
        PPosition4D(IPosition4D& i);

        IPosition4D&    m_interface;
        Vector4D        m_position;
    };
}

