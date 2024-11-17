////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3M.hpp>

namespace yq::tachyon {
    class PPosition3M : public Proxy, public IPosition3M {
    public:
    
        Vector3M    position3m() const override {  return m_position;  }
        
        void        position3m(set_t, const Vector3M&) override;
        void        position3m(move_t, const Vector3M&) override;

    private:
        PPosition3M(IPosition3M& i);

        IPosition3M&    m_interface;
        Vector3M        m_position;
    };
}

