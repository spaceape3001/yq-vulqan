////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraController.hpp"
#include <yt/api/ControllerInfoWriter.hpp>
#include <yt/api/Frame.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/YawBy.hpp>
#include <ya/events/KeyPressEvent.hpp>
#include <yt/logging.hpp>

using namespace yq;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(CameraController)

CameraController::CameraController(TypedID t) : Controller(), m_camera(t)
{
}

CameraController::~CameraController()
{
}

void CameraController::on_key_press(const KeyPressEvent& evt)
{
    switch(evt.key()){
    case KeyCode::UpArrow:
        send(new PitchBy({.target=m_camera}, 10._deg));
        break;
    case KeyCode::DownArrow:
        send(new PitchBy({.target=m_camera}, -10._deg));
        break;
    case KeyCode::LeftArrow:
        send(new YawBy({.target=m_camera}, 10._deg));
        break;
    case KeyCode::RightArrow:
        send(new YawBy({.target=m_camera}, -10._deg));
        break;
    default:
        break;
    }
}

void CameraController::init_info()
{
    auto w = writer<CameraController>();
    w.description("Camera SDK Example Controller");
    w.slot(&CameraController::on_key_press);
}
