////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/CameraCommand.hpp>
#include <yq/shape/Rectangle2.hpp>

namespace yq::tachyon {
    class CameraSetScreen : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraSetScreen, CameraCommand)
    public:
    
        CameraSetScreen(CameraID, const Rectangle2D&, const Param& p = {});
        virtual ~CameraSetScreen();
        
        static void init_info();
        
        const Rectangle2D&  screen() const { return m_screen; }
        
        const Vector2D& position() const { return m_screen.position; }
        const Size2D&   size() const { return m_screen.size; }
        double          x() const { return m_screen.position.x; }
        double          y() const { return m_screen.position.y; }
        double          width() const { return m_screen.size.x; }
        double          height() const { return m_screen.size.y; }
        
    private:
        const Rectangle2D m_screen;
    };
}
