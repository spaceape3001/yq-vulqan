////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IScreenScaleM.hpp>

namespace yq::tachyon {
    class PScreenScaleM : public Proxy, public IScreenScaleM  /* TODO: public public IScale */ {
    public:
        Meter       screen_scale() const override {  return m_screenScale;  }
        bool        screen_scale(disabled_k) const override;
        bool        screen_scale(settable_k) const override;
        bool        screen_scale(addable_k) const override;
        bool        screen_scale(multipliable_k) const override;
        
        void        screen_scale(set_k, Meter) override;

        void        screen_scale(add_k, Meter) override;
        void        screen_scale(multiply_k, double) override;

        const Meter&  screen_scale(ref_k) const {  return m_screenScale;  }

        PScreenScaleM(const IScreenScaleM& i);
        ~PScreenScaleM();

    private:
        const Meter  m_screenScale;
    };
}

