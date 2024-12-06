////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4M.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class PPosition4M : public Proxy, public IPosition4M  /* TODO: public IPosition4D, public IPosition4I, public IPosition4, public IPosition */  {
    public:
    
        Vector4M    position4m() const override {  return m_position;  }
        bool        position4m(disabled_t) const override;
        bool        position4m(settable_t) const override;
        bool        position4m(adjustable_t) const override;
        
        void        position4m(set_t, const Vector4M&) override;
        void        position4m(adjust_t, const Vector4M&) override;

        PPosition4M(const IPosition4M& i);

    private:
        Vector4M        m_position;
    };
}

