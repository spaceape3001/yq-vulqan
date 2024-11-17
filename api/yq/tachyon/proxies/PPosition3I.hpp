////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3I.hpp>

namespace yq::tachyon {
    class PPosition3I : public Proxy, public IPosition3I {
    public:
    
        Vector3I    position3i() const override {  return m_position;  }
        
        void        position3i(set_t, const Vector3I&) override;
        void        position3i(move_t, const Vector3I&) override;

    private:
        PPosition3I(IPosition3I& i);

        IPosition3I&    m_interface;
        Vector3I        m_position;
    };
}

