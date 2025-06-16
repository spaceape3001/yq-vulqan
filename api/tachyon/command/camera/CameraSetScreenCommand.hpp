////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/shape/Rectangle2.hpp>

namespace yq::tachyon {
    class CameraSetScreenCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraSetScreenCommand, CameraCommand)
    public:
    
        CameraSetScreenCommand(const Header&, const Rectangle2D&);
        
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
        CameraSetScreenCommand(const CameraSetScreenCommand&, const Header&);
        virtual ~CameraSetScreenCommand();
    
    private:
        Rectangle2D m_screen;
        
        CameraSetScreenCommand(const CameraSetScreenCommand&) = delete;
        CameraSetScreenCommand(CameraSetScreenCommand&&) = delete;
        CameraSetScreenCommand& operator=(const CameraSetScreenCommand&) = delete;
        CameraSetScreenCommand& operator=(CameraSetScreenCommand&&) = delete;
    };
}
