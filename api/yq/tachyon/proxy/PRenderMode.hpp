////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IRenderMode.hpp>

namespace yq::tachyon {
    class PRenderMode : public Proxy, public IRenderMode {
    public:
    
        virtual RenderMode    render_mode() const override;

        virtual bool    render_mode(disabled_k) const override;
        virtual bool    render_mode(settable_k) const override;
        
        virtual void    render_mode(set_k, RenderMode) override;

        PRenderMode(const IRenderMode& i);
        ~PRenderMode();

    private:
        const RenderMode  m_renderMode;
    };
}
