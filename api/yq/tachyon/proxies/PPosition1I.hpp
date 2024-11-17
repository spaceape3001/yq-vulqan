////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1I.hpp>

namespace yq::tachyon {
    class PPosition1I : public Proxy, public IPosition1I {
    public:
    
        Vector1I    position1i() const override {  return m_position;  }
        
        void        position1i(set_t, const Vector1I&) override;
        void        position1i(move_t, const Vector1I&) override;

    private:
        PPosition1I(IPosition1I& i);

        IPosition1I&    m_interface;
        Vector1I        m_position;
    };
}

