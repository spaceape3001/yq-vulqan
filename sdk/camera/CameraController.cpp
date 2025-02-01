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

using namespace yq;
using namespace yq::tachyon;

YQ_TACHYON_IMPLEMENT(CameraController)

CameraController::CameraController(const Param& p) : Controller(), m_camera(p.camera), m_listen(p.listen)
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

Execution  CameraController::setup(const Context& ctx)
{
    if(!m_init){
        const Frame*    cur = Frame::current();
        if(!cur)
            return WAIT;
        
        if(!cur->contains(m_camera))
            return WAIT;

        if(!cur->contains(m_listen))
            return WAIT;
        
        cmd_control(m_camera);
        cmd_listen(m_listen);
        m_init  = true;
    }
    return Controller::setup(ctx);
}

void CameraController::init_info()
{
    auto w = writer<CameraController>();
    w.slot(&CameraController::on_key_press);
}
