////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IBgColor.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class PBgColor : public Proxy, public IBgColor {
    public:
    
        virtual RGBA4F  bgcolor() const override;

        virtual bool    bgcolor(disabled_k) const override;
        virtual bool    bgcolor(settable_k) const override;
        
        virtual void    bgcolor(set_k, const RGBA4F&) override;

        PBgColor(const IBgColor& i);
        ~PBgColor();

    private:
        const RGBA4F  m_bgcolor;
    };
}
