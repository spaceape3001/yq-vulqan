////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Space3Controller.hpp"
#include <yt/api/ControllerInfoWriter.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/AddPositionZ.hpp>
#include <ya/commands/spatial/MoveByX.hpp>
#include <ya/commands/spatial/MoveByY.hpp>
#include <ya/commands/spatial/MoveByZ.hpp>
#include <ya/commands/spatial/PitchBy.hpp>
#include <ya/commands/spatial/RollBy.hpp>
#include <ya/commands/spatial/YawBy.hpp>
#include <ya/events/KeyPressEvent.hpp>
#include <ya/events/KeyRepeatEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Space³Controller)

namespace yq::tachyon {
    Space³Controller::Space³Controller(TypedID t) 
    {
        set_target(t);
    }
    
    Space³Controller::~Space³Controller()
    {
    }
    
    void    Space³Controller::on_key_press(const KeyPressEvent&evt)
    {
        switch(evt.key()){
        case KeyCode::A:
            send(new MoveByʸ({.target=m_target}, m_switchDir * m_vP.press ));
            break;
        case KeyCode::D:
            send(new MoveByʸ({.target=m_target}, m_switchDir * m_vN.press ));
            break;
        case KeyCode::W:
            send(new MoveByˣ({.target=m_target}, m_switchDir * m_uP.press ));
            break;
        case KeyCode::S:
            send(new MoveByˣ({.target=m_target}, m_switchDir * m_uN.press ));
            break;
        case KeyCode::Q:
            send(new MoveByᶻ({.target=m_target}, m_switchDir * m_wP.press ));
            break;
        case KeyCode::E:
            send(new MoveByᶻ({.target=m_target}, m_switchDir * m_wN.press ));
            break;
        case KeyCode::U:
            send(new AddPositionᶻ({.target=m_target}, m_switchDir * m_zP.press ));
            break;
        case KeyCode::O:
            send(new AddPositionᶻ({.target=m_target}, m_switchDir * m_zN.press ));
            break;
        case KeyCode::I:
            send(new AddPositionˣ({.target=m_target}, m_switchDir * m_xP.press ));
            break;
        case KeyCode::K:
            send(new AddPositionˣ({.target=m_target}, m_switchDir * m_xN.press ));
            break;
        case KeyCode::J:
            send(new AddPositionʸ({.target=m_target}, m_switchDir * m_yP.press ));
            break;
        case KeyCode::L:
            send(new AddPositionʸ({.target=m_target}, m_switchDir * m_yN.press ));
            break;
        case KeyCode::Kp2:
            send(new PitchBy({.target=m_target}, unit::Degree(m_switchDir * m_θN.press) ));
            break;
        case KeyCode::Kp8:
            send(new PitchBy({.target=m_target}, unit::Degree(m_switchDir * m_θP.press) ));
            break;
        case KeyCode::Kp7:
            send(new RollBy({.target=m_target}, unit::Degree(m_switchDir * m_φN.press) ));
            break;
        case KeyCode::Kp9:
            send(new RollBy({.target=m_target}, unit::Degree(m_switchDir * m_φP.press) ));
            break;
        case KeyCode::Kp4:
            send(new YawBy({.target=m_target}, unit::Degree(m_switchDir * m_λP.press) ));
            break;
        case KeyCode::Kp6:
            send(new YawBy({.target=m_target}, unit::Degree(m_switchDir * m_λN.press) ));
            break;
        default:
            break;
        }
    }
    
    void    Space³Controller::on_key_repeat(const KeyRepeatEvent&evt)
    {
    }

    void    Space³Controller::set_target(TypedID t)
    {
        m_target = t;
        if(m_target(Type::Camera)){
            m_switchDir = -1.;
        } else {
            m_switchDir = 1.;
        }
    }
    
    void Space³Controller::init_info()
    {
        auto w = writer<Space³Controller>();
        w.description("Controller for 3D spatials");
        w.slot(&Space³Controller::on_key_press);
        w.slot(&Space³Controller::on_key_repeat);
    }
}
