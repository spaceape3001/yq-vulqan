////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Space3Controller.hpp"
#include <tachyon/api/Context.hpp>
#include <tachyon/api/ControllerInfoWriter.hpp>
#include <tachyon/command/controller/SetTargetCommand.hpp>
#include <tachyon/command/gamepad/GamepadZeroCommand.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/AddPositionZCommand.hpp>
#include <tachyon/command/position/MoveByXCommand.hpp>
#include <tachyon/command/position/MoveByYCommand.hpp>
#include <tachyon/command/position/MoveByZCommand.hpp>
#include <tachyon/command/orientation/PitchByCommand.hpp>
#include <tachyon/command/orientation/RollByCommand.hpp>
#include <tachyon/command/orientation/YawByCommand.hpp>
#include <tachyon/event/keyboard/KeyPressEvent.hpp>
#include <tachyon/event/keyboard/KeyRepeatEvent.hpp>
#include <tachyon/event/gamepad/GamepadAxisEvent.hpp>
#include <tachyon/event/gamepad/GamepadPressEvent.hpp>
#include <tachyon/event/gamepad/GamepadZeroEvent.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Space³Controller)

namespace yq::tachyon {
    Space³Controller::Space³Controller(const Param&p) : Space³Controller({}, p)
    {
    }

    Space³Controller::Space³Controller(TypedID t, const Param&p) : 
        Controller(p), m_keyboardEnable(p.keyboard), m_gamepadEnable(p.gamepad)
    {
        if(t){
            set_target(t);
        }
    }
    
    Space³Controller::~Space³Controller()
    {
    }
    
    void    Space³Controller::on_gamepad_axis(const GamepadAxisEvent&evt)
    {
        if(enabled() && m_gamepadEnable){
            // used when needing to know axis mappings
            // tachyonInfo << "Space³Controller::on_gamepad_axis(" << evt.axis() << " -> " << evt.value() << ")";
            switch(evt.axis()){
            case 0:
                switch(m_modeLeft){
                case Mode::HP:
                    m_λ.input   = evt.value();
                    break;
                case Mode::PR:
                    m_θ.input   = evt.value();
                    break;
                case Mode::RH:
                    m_φ.input   = evt.value();
                    break;
                case Mode::UV:
                    m_u.input   = evt.value();
                    break;
                case Mode::VW:
                    m_v.input   = evt.value();
                    break;
                case Mode::WU:
                    m_w.input   = evt.value();
                    break;
                }
                break;
            case 1:
                switch(m_modeLeft){
                case Mode::HP:
                    m_θ.input   = evt.value();
                    break;
                case Mode::PR:
                    m_φ.input   = evt.value();
                    break;
                case Mode::RH:
                    m_λ.input   = evt.value();
                    break;
                case Mode::UV:
                    m_v.input   = evt.value();
                    break;
                case Mode::VW:
                    m_w.input   = evt.value();
                    break;
                case Mode::WU:
                    m_u.input   = evt.value();
                    break;
                }
                break;
            case 3:
                switch(m_modeRight){
                case Mode::HP:
                    m_λ.input   = evt.value();
                    break;
                case Mode::PR:
                    m_θ.input   = evt.value();
                    break;
                case Mode::RH:
                    m_φ.input   = evt.value();
                    break;
                case Mode::UV:
                    m_u.input   = evt.value();
                    break;
                case Mode::VW:
                    m_v.input   = evt.value();
                    break;
                case Mode::WU:
                    m_w.input   = evt.value();
                    break;
                }
                break;
            case 4:
                switch(m_modeRight){
                case Mode::HP:
                    m_θ.input   = evt.value();
                    break;
                case Mode::PR:
                    m_φ.input   = evt.value();
                    break;
                case Mode::RH:
                    m_λ.input   = evt.value();
                    break;
                case Mode::UV:
                    m_v.input   = evt.value();
                    break;
                case Mode::VW:
                    m_w.input   = evt.value();
                    break;
                case Mode::WU:
                    m_u.input   = evt.value();
                    break;
                }
                break;
            default:
                break;
            }
        }
    }

    void    Space³Controller::on_gamepad_press(const GamepadPressEvent&evt)
    {
        if(enabled() && m_gamepadEnable){
            // used when needing to know button mappings
            // tachyonInfo << "Space³Controller::on_gamepad_press(" << evt.button() << ")";

            bool    modeChange  = false;

            switch(evt.button()){
            case 6: // cycle the modes
                switch(m_modeLeft){
                case Mode::UV:
                    m_modeLeft  = Mode::VW;
                    tachyonInfo << "Left joystick is in V-W mode";
                    break;
                case Mode::VW:
                    m_modeLeft  = Mode::WU;
                    tachyonInfo << "Left joystick is in W-V mode";
                    break;
                case Mode::WU:
                default:
                    m_modeLeft  = Mode::UV;
                    tachyonInfo << "Left joystick is in U-V mode";
                    break;
                }
                modeChange = true;
                break;
            case 7:
                switch(m_modeRight){
                case Mode::HP:
                    m_modeRight  = Mode::PR;
                    tachyonInfo << "Right joystick is in P-R mode";
                    break;
                case Mode::PR:
                    m_modeRight  = Mode::RH;
                    tachyonInfo << "Right joystick is in R-H mode";
                    break;
                case Mode::RH:
                default:
                    m_modeRight  = Mode::HP;
                    tachyonInfo << "Right joystick is in R-H mode";
                    break;
                }
                modeChange = true;
                break;
            case 9:
            case 10:
                m_joyLockout    = true;
                send(new GamepadZeroCommand({.target=evt.source()})); 
                break;
            }
            
            if(modeChange){
                m_θ.input       = 0.;
                m_λ.input       = 0.;
                m_φ.input       = 0.;
                m_u.input       = 0.;
                m_v.input       = 0.;
                m_w.input       = 0.;
            }
        }
    }

    void    Space³Controller::on_gamepad_zero(const GamepadZeroEvent&evt)
    {
        if(enabled() && m_gamepadEnable){
            m_θ.input       = 0.;
            m_λ.input       = 0.;
            m_φ.input       = 0.;
            m_u.input       = 0.;
            m_v.input       = 0.;
            m_w.input       = 0.;
            m_joyLockout    = false;
        }
    }

    void    Space³Controller::on_key_press(const KeyPressEvent&evt)
    {
        if(enabled() && m_keyboardEnable && m_target){
            switch(evt.key()){
            case KeyCode::A:
                send(new MoveByʸCommand({.target=m_target}, m_vN.press ));
                break;
            case KeyCode::D:
                send(new MoveByʸCommand({.target=m_target}, m_vP.press ));
                break;
            case KeyCode::W:
                send(new MoveByˣCommand({.target=m_target}, m_uP.press ));
                break;
            case KeyCode::S:
                send(new MoveByˣCommand({.target=m_target}, m_uN.press ));
                break;
            case KeyCode::Q:
                send(new MoveByᶻCommand({.target=m_target}, m_wN.press ));
                break;
            case KeyCode::E:
                send(new MoveByᶻCommand({.target=m_target}, m_wP.press ));
                break;
            case KeyCode::U:
                send(new AddPositionᶻCommand({.target=m_target}, m_zN.press ));
                break;
            case KeyCode::O:
                send(new AddPositionᶻCommand({.target=m_target}, m_zP.press ));
                break;
            case KeyCode::I:
                send(new AddPositionˣCommand({.target=m_target}, m_xP.press ));
                break;
            case KeyCode::K:
                send(new AddPositionˣCommand({.target=m_target}, m_xN.press ));
                break;
            case KeyCode::J:
                send(new AddPositionʸCommand({.target=m_target}, m_yN.press ));
                break;
            case KeyCode::L:
                send(new AddPositionʸCommand({.target=m_target}, m_yP.press ));
                break;
                
            case KeyCode::Kp2:
                send(new PitchByCommand({.target=m_target}, unit::Degree(m_θN.press) ));
                break;
            case KeyCode::Kp8:
                send(new PitchByCommand({.target=m_target}, unit::Degree(m_θP.press) ));
                break;
                
            case KeyCode::Kp7:
                send(new RollByCommand({.target=m_target}, unit::Degree(m_φN.press) ));
                break;
            case KeyCode::Kp9:
                send(new RollByCommand({.target=m_target}, unit::Degree(m_φP.press) ));
                break;
                
            case KeyCode::Kp4:
                send(new YawByCommand({.target=m_target}, unit::Degree(m_λN.press) ));
                break;
            case KeyCode::Kp6:
                send(new YawByCommand({.target=m_target}, unit::Degree(m_λP.press) ));
                break;
            default:
                break;
            }
        }
    }
    
    void    Space³Controller::on_key_repeat(const KeyRepeatEvent&evt)
    {
        if(enabled() && m_keyboardEnable && m_target){
            switch(evt.key()){
            case KeyCode::A:
                send(new MoveByʸCommand({.target=m_target}, m_vN.repeat ));
                break;
            case KeyCode::D:
                send(new MoveByʸCommand({.target=m_target}, m_vP.repeat ));
                break;
            case KeyCode::W:
                send(new MoveByˣCommand({.target=m_target}, m_uP.repeat ));
                break;
            case KeyCode::S:
                send(new MoveByˣCommand({.target=m_target}, m_uN.repeat ));
                break;
            case KeyCode::Q:
                send(new MoveByᶻCommand({.target=m_target}, m_wN.repeat ));
                break;
            case KeyCode::E:
                send(new MoveByᶻCommand({.target=m_target}, m_wP.repeat ));
                break;
            case KeyCode::U:
                send(new AddPositionᶻCommand({.target=m_target}, m_zN.repeat ));
                break;
            case KeyCode::O:
                send(new AddPositionᶻCommand({.target=m_target}, m_zP.repeat ));
                break;
            case KeyCode::I:
                send(new AddPositionˣCommand({.target=m_target}, m_xN.repeat ));
                break;
            case KeyCode::K:
                send(new AddPositionˣCommand({.target=m_target}, m_xP.repeat ));
                break;
            case KeyCode::J:
                send(new AddPositionʸCommand({.target=m_target}, m_yP.repeat ));
                break;
            case KeyCode::L:
                send(new AddPositionʸCommand({.target=m_target}, m_yN.repeat ));
                break;
            case KeyCode::Kp2:
                send(new PitchByCommand({.target=m_target}, unit::Degree(m_θN.repeat) ));
                break;
            case KeyCode::Kp8:
                send(new PitchByCommand({.target=m_target}, unit::Degree(m_θP.repeat) ));
                break;
            case KeyCode::Kp7:
                send(new RollByCommand({.target=m_target}, unit::Degree(m_φN.repeat) ));
                break;
            case KeyCode::Kp9:
                send(new RollByCommand({.target=m_target}, unit::Degree(m_φP.repeat) ));
                break;
            case KeyCode::Kp4:
                send(new YawByCommand({.target=m_target}, unit::Degree(m_λN.repeat) ));
                break;
            case KeyCode::Kp6:
                send(new YawByCommand({.target=m_target}, unit::Degree(m_λP.repeat) ));
                break;
            default:
                break;
            }
        }
    }

    void    Space³Controller::on_set_target_command(const SetTargetCommand& cmd)
    {
        if(cmd.target() != id())
            return;
        m_target    = cmd.target();
    }

    void    Space³Controller::set_target(TypedID t)
    {
        m_target = t;
    }

    Execution   Space³Controller::tick(const Context& ctx)
    {
        if(!enabled())
            return {};
            
        if(enabled() && m_gamepadEnable && m_target && !m_joyLockout){
            if(m_θ.input){
                send(new PitchByCommand({.target=m_target}, unit::Degree(m_θ.input*m_θ.gain*ctx.Δwall.value) ));
            }
            if(m_λ.input){
                send(new YawByCommand({.target=m_target}, unit::Degree(m_λ.input*m_λ.gain*ctx.Δwall.value) ));
            }
            if(m_φ.input){
                send(new RollByCommand({.target=m_target}, unit::Degree(m_φ.input*m_φ.gain*ctx.Δwall.value) ));
            }
            if(m_u.input){
                send(new MoveByˣCommand({.target=m_target}, m_u.input*m_u.gain*ctx.Δwall.value));
            }
            if(m_v.input){
                send(new MoveByʸCommand({.target=m_target}, m_v.input*m_v.gain*ctx.Δwall.value));
            }
            if(m_w.input){
                send(new MoveByᶻCommand({.target=m_target}, m_w.input*m_w.gain*ctx.Δwall.value));
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
        w.slot(&Space³Controller::on_set_target_command);
    }
}
