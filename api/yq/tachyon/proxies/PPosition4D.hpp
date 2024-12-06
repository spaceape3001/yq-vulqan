////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4D.hpp>

namespace yq::tachyon {
    class PPosition4D : public Proxy, public IPosition4D  /* TODO: public IPosition4I, public IPosition4, public IPosition */  {
    public:
    
        Vector4D    position4d() const override {  return m_position;  }
        bool        position4d(disabled_t) const override;
        bool        position4d(settable_t) const override;
        bool        position4d(adjustable_t) const override;
        
        void        position4d(set_t, const Vector4D&) override;
        void        position4d(adjust_t, const Vector4D&) override;

        PPosition4D(const IPosition4D& i);

    private:
        Vector4D        m_position;
    };
}

