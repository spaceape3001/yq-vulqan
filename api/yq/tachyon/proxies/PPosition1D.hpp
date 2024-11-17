////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1D.hpp>

namespace yq::tachyon {
    class PPosition1D : public Proxy, public IPosition1D {
    public:
    
        Vector1D    position1d() const override {  return m_position;  }
        
        void        position1d(set_t, const Vector1D&) override;
        void        position1d(move_t, const Vector1D&) override;

    private:
        PPosition1D(IPosition1D& i);

        IPosition1D&    m_interface;
        Vector1D        m_position;
    };
}

