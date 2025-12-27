////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/WidgetCommand.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>

namespace yq::tachyon {
    class SetRenderModeCommand : public WidgetCommand {
        YQ_OBJECT_DECLARE(SetRenderModeCommand, WidgetCommand)
    public:
        SetRenderModeCommand(const Header&, RenderMode);
        
        RenderMode  render_mode() const { return m_renderMode; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRenderModeCommand(const SetRenderModeCommand&, const Header&);
        ~SetRenderModeCommand();
    private:
        RenderMode     m_renderMode;
        
        SetRenderModeCommand(const SetRenderModeCommand&) = delete;
        SetRenderModeCommand(SetRenderModeCommand&&) = delete;
        SetRenderModeCommand& operator=(const SetRenderModeCommand&) = delete;
        SetRenderModeCommand& operator=(SetRenderModeCommand&&) = delete;
    };
}
