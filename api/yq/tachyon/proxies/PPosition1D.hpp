////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1D.hpp>

namespace yq::tachyon {
    class PPosition1D : public Proxy, public IPosition1D  /* TODO: public IPosition1I, public IPosition1, public IPosition */  {
    public:
    
        Vector1D    position1d() const override {  return m_position;  }
        bool        position1d(disabled_k) const override;
        bool        position1d(settable_k) const override;
        bool        position1d(adjustable_k) const override;
        
        void        position1d(set_k, const Vector1D&) override;
        void        position1d(adjust_k, const Vector1D&) override;

        PPosition1D(const IPosition1D& i);

    private:
        Vector1D        m_position;
    };
}

