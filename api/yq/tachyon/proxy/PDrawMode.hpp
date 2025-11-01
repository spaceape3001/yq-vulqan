////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/IDrawMode.hpp>

namespace yq::tachyon {
    class PDrawMode : public Proxy, public IDrawMode {
    public:
    
        virtual DrawMode    draw_mode() const override;
        virtual DrawMode    draw_mode(use_k) const override;

        virtual bool    draw_mode(disabled_k) const override;
        virtual bool    draw_mode(settable_k) const override;
        
        virtual void    draw_mode(set_k, DrawMode) override;

        PDrawMode(const IDrawMode& i);
        ~PDrawMode();

    private:
        const DrawMode  m_drawMode;
        const DrawMode  m_drawModeUse;
    };
}
