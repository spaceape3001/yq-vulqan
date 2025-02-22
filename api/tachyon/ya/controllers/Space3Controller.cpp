////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Space3Controller.hpp"
#include <yt/api/Context.hpp>
#include <yt/api/ControllerInfoWriter.hpp>
#include <ya/commands/gamepad/GamepadZeroCommand.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/AddPositionZ.hpp>
#include <ya/commands/spatial/MoveByX.hpp>
#include <ya/commands/spatial/MoveByY.hpp>
#include <ya/commands/spatial/MoveByZ.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/RollBy.hpp>
#include <ya/commands/spatial/YawBy.hpp>
#include <ya/events/keyboard/KeyPressEvent.hpp>
#include <ya/events/keyboard/KeyRepeatEvent.hpp>
#include <ya/events/gamepad/GamepadAxisEvent.hpp>
#include <ya/events/gamepad/GamepadPressEvent.hpp>
#include <ya/events/gamepad/GamepadZeroEvent.hpp>
#include <yt/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Space³Controller)

namespace yq::tachyon {
    Space³Controller::Space³Controller(TypedID t) 
    {
        set_target(t);
    }
    
    Space³Controller::~Space³Controller()
    {
    }
    
    void    Space³Controller::on_gamepad_axis(const GamepadAxisEvent&evt)
    {
        switch(evt.axis()){
        case 0:
            m_λ.input   = evt.value();
            break;
        case 1:
            m_θ.input   = evt.value();
            break;
        default:
            break;
        }
    }

    void    Space³Controller::on_gamepad_press(const GamepadPressEvent&evt)
    {
        if(evt.button() == 9){  // currently hardwired
            m_joyLockout    = true;
            send(new GamepadZeroCommand({.target=evt.source()})); 
        }
    }

    void    Space³Controller::on_gamepad_zero(const GamepadZeroEvent&evt)
    {
        m_θ.input       = 0.;
        m_λ.input       = 0.;
        m_joyLockout    = false;
    }

    void    Space³Controller::on_key_press(const KeyPressEvent&evt)
    {
        switch(evt.key()){
        case KeyCode::A:
            send(new MoveByʸ({.target=m_target}, m_vN.press ));
            break;
        case KeyCode::D:
            send(new MoveByʸ({.target=m_target}, m_vP.press ));
            break;
        case KeyCode::W:
            send(new MoveByˣ({.target=m_target}, m_uP.press ));
            break;
        case KeyCode::S:
            send(new MoveByˣ({.target=m_target}, m_uN.press ));
            break;
        case KeyCode::Q:
            send(new MoveByᶻ({.target=m_target}, m_wN.press ));
            break;
        case KeyCode::E:
            send(new MoveByᶻ({.target=m_target}, m_wP.press ));
            break;
        case KeyCode::U:
            send(new AddPositionᶻ({.target=m_target}, m_zN.press ));
            break;
        case KeyCode::O:
            send(new AddPositionᶻ({.target=m_target}, m_zP.press ));
            break;
        case KeyCode::I:
            send(new AddPositionˣ({.target=m_target}, m_xP.press ));
            break;
        case KeyCode::K:
            send(new AddPositionˣ({.target=m_target}, m_xN.press ));
            break;
        case KeyCode::J:
            send(new AddPositionʸ({.target=m_target}, m_yN.press ));
            break;
        case KeyCode::L:
            send(new AddPositionʸ({.target=m_target}, m_yP.press ));
            break;
            
        case KeyCode::Kp2:
            send(new PitchBy({.target=m_target}, unit::Degree(m_θN.press) ));
            break;
        case KeyCode::Kp8:
            send(new PitchBy({.target=m_target}, unit::Degree(m_θP.press) ));
            break;
            
        case KeyCode::Kp7:
            send(new RollBy({.target=m_target}, unit::Degree(m_φN.press) ));
            break;
        case KeyCode::Kp9:
            send(new RollBy({.target=m_target}, unit::Degree(m_φP.press) ));
            break;
            
        case KeyCode::Kp4:
            send(new YawBy({.target=m_target}, unit::Degree(m_λN.press) ));
            break;
        case KeyCode::Kp6:
            send(new YawBy({.target=m_target}, unit::Degree(m_λP.press) ));
            break;
        default:
            break;
        }
    }
    
    void    Space³Controller::on_key_repeat(const KeyRepeatEvent&evt)
    {
        switch(evt.key()){
        case KeyCode::A:
            send(new MoveByʸ({.target=m_target}, m_vN.repeat ));
            break;
        case KeyCode::D:
            send(new MoveByʸ({.target=m_target}, m_vP.repeat ));
            break;
        case KeyCode::W:
            send(new MoveByˣ({.target=m_target}, m_uP.repeat ));
            break;
        case KeyCode::S:
            send(new MoveByˣ({.target=m_target}, m_uN.repeat ));
            break;
        case KeyCode::Q:
            send(new MoveByᶻ({.target=m_target}, m_wN.repeat ));
            break;
        case KeyCode::E:
            send(new MoveByᶻ({.target=m_target}, m_wP.repeat ));
            break;
        case KeyCode::U:
            send(new AddPositionᶻ({.target=m_target}, m_zN.repeat ));
            break;
        case KeyCode::O:
            send(new AddPositionᶻ({.target=m_target}, m_zP.repeat ));
            break;
        case KeyCode::I:
            send(new AddPositionˣ({.target=m_target}, m_xN.repeat ));
            break;
        case KeyCode::K:
            send(new AddPositionˣ({.target=m_target}, m_xP.repeat ));
            break;
        case KeyCode::J:
            send(new AddPositionʸ({.target=m_target}, m_yP.repeat ));
            break;
        case KeyCode::L:
            send(new AddPositionʸ({.target=m_target}, m_yN.repeat ));
            break;
        case KeyCode::Kp2:
            send(new PitchBy({.target=m_target}, unit::Degree(m_θN.repeat) ));
            break;
        case KeyCode::Kp8:
            send(new PitchBy({.target=m_target}, unit::Degree(m_θP.repeat) ));
            break;
        case KeyCode::Kp7:
            send(new RollBy({.target=m_target}, unit::Degree(m_φN.repeat) ));
            break;
        case KeyCode::Kp9:
            send(new RollBy({.target=m_target}, unit::Degree(m_φP.repeat) ));
            break;
        case KeyCode::Kp4:
            send(new YawBy({.target=m_target}, unit::Degree(m_λN.repeat) ));
            break;
        case KeyCode::Kp6:
            send(new YawBy({.target=m_target}, unit::Degree(m_λP.repeat) ));
            break;
        default:
            break;
        }
    }

    void    Space³Controller::set_target(TypedID t)
    {
        m_target = t;
    }

    Execution   Space³Controller::tick(const Context& ctx)
    {
        if(!m_joyLockout){
            if(m_θ.input){
                send(new PitchBy({.target=m_target}, unit::Degree(m_θ.input*m_θ.gain*ctx.Δwall.value) ));
            }
            if(m_λ.input){
                send(new YawBy({.target=m_target}, unit::Degree(m_λ.input*m_λ.gain*ctx.Δwall.value) ));
            }
        }
        return {};
    }
    
    void Space³Controller::init_info()
    {
        auto w = writer<Space³Controller>();
        w.description("Controller for 3D spatials");
        w.slot(&Space³Controller::on_gamepad_axis);
        w.slot(&Space³Controller::on_gamepad_press);
        w.slot(&Space³Controller::on_gamepad_zero);
        w.slot(&Space³Controller::on_key_press);
        w.slot(&Space³Controller::on_key_repeat);
    }
}
