////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IColor.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class PColor : public Proxy, public IColor {
    public:
    
        virtual RGBA4F  color() const override;

        virtual bool    color(disabled_k) const override;
        virtual bool    color(settable_k) const override;
        
        virtual void    color(set_k, const RGBA4F&) override;

        PColor(const IColor& i);
        ~PColor();

    private:
        const RGBA4F  m_color;
    };
}
