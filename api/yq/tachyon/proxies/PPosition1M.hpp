////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1M.hpp>

namespace yq::tachyon {
    class PPosition1M : public Proxy, public IPosition1M {
    public:
    
        Vector1M    position1m() const override {  return m_position;  }
        
        void        position1m(set_t, const Vector1M&) override;
        void        position1m(move_t, const Vector1M&) override;

    private:
        PPosition1M(IPosition1M& i);

        IPosition1M&    m_interface;
        Vector1M        m_position;
    };
}

