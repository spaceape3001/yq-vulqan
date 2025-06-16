////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/shape/Rectangle2.hpp>

namespace yq::tachyon {
    class SetScreenCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(SetScreenCommand, CameraCommand)
    public:
    
        SetScreenCommand(const Header&, const Rectangle2D&);
        
        static void init_info();
        
        const Rectangle2D&  screen() const { return m_screen; }
        
        const Vector2D& position() const { return m_screen.position; }
        const Size2D&   size() const { return m_screen.size; }
        double          x() const { return m_screen.position.x; }
        double          y() const { return m_screen.position.y; }
        double          width() const { return m_screen.size.x; }
        double          height() const { return m_screen.size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScreenCommand(const SetScreenCommand&, const Header&);
        virtual ~SetScreenCommand();
    
    private:
        Rectangle2D m_screen;
        
        SetScreenCommand(const SetScreenCommand&) = delete;
        SetScreenCommand(SetScreenCommand&&) = delete;
        SetScreenCommand& operator=(const SetScreenCommand&) = delete;
        SetScreenCommand& operator=(SetScreenCommand&&) = delete;
    };
}
