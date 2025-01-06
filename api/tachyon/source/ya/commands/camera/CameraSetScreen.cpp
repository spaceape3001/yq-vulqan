////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/camera/CameraSetScreen.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetScreen)

namespace yq::tachyon {
    
    CameraSetScreen::CameraSetScreen(CameraID cid, const Rectangle2D& r, const Param& p)
        : CameraCommand(cid, p), m_screen(r)
    {
    }
    
    CameraSetScreen::~CameraSetScreen()
    {
    }
    
    void CameraSetScreen::init_info()
    {
        auto w = writer<CameraSetScreen>();
        w.description("Sets a camera's screen rectangle");
    }
}
