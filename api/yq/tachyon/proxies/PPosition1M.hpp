////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition1M.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class PPosition1M : public Proxy, public IPosition1M  /* TODO: public IPosition1D, public IPosition1I, public IPosition1, public IPosition */  {
    public:
    
        Vector1M    position1m() const override {  return m_position;  }
        bool        position1m(disabled_k) const override;
        bool        position1m(settable_k) const override;
        bool        position1m(adjustable_k) const override;
        
        void        position1m(set_k, const Vector1M&) override;
        void        position1m(adjust_k, const Vector1M&) override;

        PPosition1M(const IPosition1M& i);

    private:
        Vector1M        m_position;
    };
}

