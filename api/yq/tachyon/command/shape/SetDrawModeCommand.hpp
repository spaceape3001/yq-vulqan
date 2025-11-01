////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ShapeCommand.hpp>
#include <tachyon/pipeline/DrawMode.hpp>

namespace yq::tachyon {
    class SetDrawModeCommand : public ShapeCommand {
        YQ_OBJECT_DECLARE(SetDrawModeCommand, ShapeCommand)
    public:
        SetDrawModeCommand(const Header&, DrawMode);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        DrawMode        draw_mode() const { return m_drawMode; }
        void            set_draw_mode(DrawMode);

    protected:
        SetDrawModeCommand(const SetDrawModeCommand&, const Header&);
        virtual ~SetDrawModeCommand();
        
    private:
    
        DrawMode        m_drawMode;

        SetDrawModeCommand(const SetDrawModeCommand&) = delete;
        SetDrawModeCommand(SetDrawModeCommand&&) = delete;
        SetDrawModeCommand& operator=(const SetDrawModeCommand&) = delete;
        SetDrawModeCommand& operator=(SetDrawModeCommand&&) = delete;
    };
}
