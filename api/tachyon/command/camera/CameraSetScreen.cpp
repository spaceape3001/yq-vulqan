////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/CameraSetScreen.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetScreen)

namespace yq::tachyon {
    
    CameraSetScreen::CameraSetScreen(const Header&h, const Rectangle2D& r)
        : CameraCommand(h), m_screen(r)
    {
    }
    
    CameraSetScreen::CameraSetScreen(const CameraSetScreen& cp, const Header&h)
        : CameraCommand(cp, h), m_screen(cp.m_screen)
    {
    }
    
    CameraSetScreen::~CameraSetScreen()
    {
    }
    
    PostCPtr    CameraSetScreen::clone(rebind_k, const Header& h) const 
    {
        return new CameraSetScreen(*this, h);
    }

    void CameraSetScreen::init_info()
    {
        auto w = writer<CameraSetScreen>();
        w.description("Sets a camera's screen rectangle");
        w.property("rectangle", &CameraSetScreen::m_screen).tag(kTag_Save);
        w.property("x", &CameraSetScreen::x).tag(kTag_Log);
        w.property("y", &CameraSetScreen::y).tag(kTag_Log);
        w.property("w", &CameraSetScreen::width).tag(kTag_Log);
        w.property("h", &CameraSetScreen::height).tag(kTag_Log);
    }
}
