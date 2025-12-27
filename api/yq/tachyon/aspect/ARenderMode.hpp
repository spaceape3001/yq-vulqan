////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/interface/IRenderMode.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetRenderModeCommand;
    
    class ARenderMode : public IRenderMode, public virtual Tachyon::Helper {
    public:

        static constexpr const RenderMode     kDefRenderMode    = RenderMode::Simple;
    
        struct Param {
            RenderMode    render_mode   = kDefRenderMode;
        };
        
        RenderMode  render_mode() const override { return m_renderMode; }

        virtual bool    render_mode(disabled_k) const override { return false; }
        virtual bool    render_mode(settable_k) const override { return true; }
        
        // override to accept/reject
        virtual void    render_mode(set_k, RenderMode);
        
    protected:


        RenderMode    m_renderMode  = kDefRenderMode;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ARenderMode(const Param&);
        ARenderMode(RenderMode dm=kDefRenderMode);
        virtual ~ARenderMode();
        
    private:
        void    on_set_render_mode(const SetRenderModeCommand&);

    };
}
