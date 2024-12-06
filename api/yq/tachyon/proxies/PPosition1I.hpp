////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1I.hpp>

namespace yq::tachyon {
    class PPosition1I : public Proxy, public IPosition1I /* TODO: public IPosition1D, public IPosition1, public IPosition */  {
    public:
    
        Vector1I    position1i() const override {  return m_position;  }
        bool        position1i(disabled_t) const override;
        bool        position1i(settable_t) const override;
        bool        position1i(adjustable_t) const override;
        
        void        position1i(set_t, const Vector1I&) override;
        void        position1i(adjust_t, const Vector1I&) override;

        PPosition1I(const IPosition1I& i);

    private:
        Vector1I        m_position;
    };
}

