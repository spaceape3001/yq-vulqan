////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition2M.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {
    class PPosition2M : public Proxy, public IPosition2M  /* TODO: public IPosition2D, public IPosition2I, public IPosition2, public IPosition */  {
    public:
    
        Vector2M    position2m() const override {  return m_position;  }
        bool        position2m(disabled_t) const override;
        bool        position2m(settable_t) const override;
        bool        position2m(adjustable_t) const override;
        
        void        position2m(set_t, const Vector2M&) override;
        void        position2m(adjust_t, const Vector2M&) override;

        PPosition2M(const IPosition2M& i);

    private:
        Vector2M        m_position;
    };
}

