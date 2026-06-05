////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition3CMWriter.hxx"
#include "APosition3CM.hpp"
#include <yq/tachyon/command/position/centimeter/AddPosition3CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition3CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/event/spatial/centimeter/Position3CMEvent.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    APosition³CM::APosition³CM(const Centimeter3D& pos)
    {
        if(!is_nan(pos))
            m_position  = pos;
    }

    APosition³CM::APosition³CM(const Param&p) : APosition³CM(p.position)
    {
    }
    
    APosition³CM::~APosition³CM()
    {
    }

    void        APosition³CM::position(emit_k)
    {
        send(new Position³CMEvent({.source=typed()}, m_position));
    }

    void        APosition³CM::position(set_k, const Centimeter3D& sz) 
    {
        if(is_nan(sz))
            return ;
            
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition³CM::position(set_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter3D(v, m_position.y, m_position.z));
    }
    
    void        APosition³CM::position(set_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter3D(m_position.x,v, m_position.z));
    }
    
    void        APosition³CM::position(set_k, z_k, Centimeter v) 
    {
        position(SET, Centimeter3D(m_position.x, m_position.y, v));
    }
    
    void        APosition³CM::position(add_k, const Centimeter3D&v) 
    {
        position(SET, Centimeter3D( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z ));
    }
    
    void        APosition³CM::position(add_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter3D( m_position.x+v, m_position.y, m_position.z ));
    }
    
    void        APosition³CM::position(add_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter3D( m_position.x, m_position.y+v, m_position.z ));
    }
    
    void        APosition³CM::position(add_k, z_k, Centimeter v) 
    {
        position(SET, Centimeter3D( m_position.x, m_position.y, m_position.z+v ));
    }

    void        APosition³CM::position(multiply_k, double v) 
    {
        position(SET, Centimeter3D( m_position.x*v, m_position.y*v, m_position.z*v ));
    }
    
    void        APosition³CM::position(multiply_k, const Vector3D& v) 
    {
        position(SET, Centimeter3D( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z ));
    }
    
    void        APosition³CM::position(multiply_k, x_k, double v) 
    {
        position(SET, Centimeter3D( m_position.x*v, m_position.y, m_position.z ));
    }
    
    void        APosition³CM::position(multiply_k, y_k, double v) 
    {
        position(SET, Centimeter3D( m_position.x, m_position.y*v, m_position.z ));
    }
    
    void        APosition³CM::position(multiply_k, z_k, double v)
    {
        position(SET, Centimeter3D( m_position.x, m_position.y, m_position.z*v ));
    }
    
    void        APosition³CM::on_set_position3(const SetPosition³CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition³CM::on_set_positionX(const SetPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition³CM::on_set_positionY(const SetPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition³CM::on_set_positionZ(const SetPositionᶻCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition³CM::on_add_position3(const AddPosition³CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition³CM::on_add_positionX(const AddPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition³CM::on_add_positionY(const AddPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition³CM::on_add_positionZ(const AddPositionᶻCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition³CM::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³CM::on_multiply_position3(const MultiplyPosition³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³CM::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition³CM::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition³CM::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
