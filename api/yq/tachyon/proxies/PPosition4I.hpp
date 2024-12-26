////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition4D.hpp>
#include <yq/tachyon/interfaces/IPosition4I.hpp>

namespace yq::tachyon {
    class PPosition4I : public Proxy, public IPosition4I /* TODO: public IPosition4D */ {
    public:
    
        Vector4I    position4i() const override {  return m_position;  }
        bool        position4i(disabled_k) const override;
        bool        position4i(settable_k) const override;
        bool        position4i(adjustable_k) const override;
        
        void        position4i(set_k, const Vector4I&) override;
        void        position4i(adjust_k, const Vector4I&) override;

        PPosition4I(const IPosition4I& i);

    private:
        Vector4I        m_position;
    };
}

