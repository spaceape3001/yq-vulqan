////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition4CMWriter.hxx"
#include "APosition4CM.hpp"
#include <yq/tachyon/command/position/centimeter/AddPosition4CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionWCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition4CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionWCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/event/spatial/centimeter/Position4CMEvent.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    APosition⁴CM::APosition⁴CM(const Centimeter4D& pos) 
    {
        if(!is_nan(pos))
            m_position = pos;
    }
    
    APosition⁴CM::~APosition⁴CM()
    {
    }

    void        APosition⁴CM::position(emit_k)
    {
        send(new Position⁴CMEvent({.source=typed()}, m_position));
    }

    void        APosition⁴CM::position(set_k, const Centimeter4D& sz) 
    {
        if(is_nan(sz))
            return;
            
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition⁴CM::position(set_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter4D(v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(set_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter4D(m_position.x,v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(set_k, z_k, Centimeter v) 
    {
        position(SET, Centimeter4D(m_position.x, m_position.y, v, m_position.w ));
    }
    
    void        APosition⁴CM::position(set_k, w_k, Centimeter v) 
    {
        position(SET, Centimeter4D(m_position.x, m_position.y, m_position.z, v ));
    }

    void        APosition⁴CM::position(add_k, const Centimeter4D&v) 
    {
        position(SET, Centimeter4D( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z, m_position.w+v.w ));
    }
    
    void        APosition⁴CM::position(add_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter4D( m_position.x+v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(add_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter4D( m_position.x, m_position.y+v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(add_k, z_k, Centimeter v) 
    {
        position(SET, Centimeter4D( m_position.x, m_position.y, m_position.z+v, m_position.w ));
    }

    void        APosition⁴CM::position(add_k, w_k, Centimeter v) 
    {
        position(SET, Centimeter4D( m_position.x, m_position.y, m_position.z, m_position.w+v ));
    }

    void        APosition⁴CM::position(multiply_k, double v) 
    {
        position(SET, Centimeter4D( m_position.x*v, m_position.y*v, m_position.z*v, m_position.w*v ));
    }
    
    void        APosition⁴CM::position(multiply_k, const Vector4D& v) 
    {
        position(SET, Centimeter4D( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z, m_position.w*v.w ));
    }
    
    void        APosition⁴CM::position(multiply_k, x_k, double v) 
    {
        position(SET, Centimeter4D( m_position.x*v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(multiply_k, y_k, double v) 
    {
        position(SET, Centimeter4D( m_position.x, m_position.y*v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴CM::position(multiply_k, z_k, double v)
    {
        position(SET, Centimeter4D( m_position.x, m_position.y, m_position.z*v, m_position.w ));
    }
    
    void        APosition⁴CM::position(multiply_k, w_k, double v)
    {
        position(SET, Centimeter4D( m_position.x, m_position.y, m_position.z, m_position.w*v ));
    }

    void        APosition⁴CM::on_set_position4(const SetPosition⁴CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition⁴CM::on_set_positionW(const SetPositionʷCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, W, cmd.w());
    }
    
    void        APosition⁴CM::on_set_positionX(const SetPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }

    void        APosition⁴CM::on_set_positionY(const SetPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition⁴CM::on_set_positionZ(const SetPositionᶻCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition⁴CM::on_add_position4(const AddPosition⁴CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition⁴CM::on_add_positionW(const AddPositionʷCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, W, cmd.Δw());
    }
    
    void        APosition⁴CM::on_add_positionX(const AddPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }

    void        APosition⁴CM::on_add_positionY(const AddPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition⁴CM::on_add_positionZ(const AddPositionᶻCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition⁴CM::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴CM::on_multiply_position4(const MultiplyPosition⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴CM::on_multiply_positionW(const MultiplyPositionʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, W, cmd.δw());
    }
    
    void        APosition⁴CM::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }

    void        APosition⁴CM::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition⁴CM::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
