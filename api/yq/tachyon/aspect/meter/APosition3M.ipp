////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition3MWriter.hxx"

#include "APosition3M.hpp"
#include <yq/tachyon/command/position/meter/AddPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionZMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition3MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionZMCommand.hpp>
#include <yq/tachyon/event/spatial/meter/Position3MEvent.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    APosition³M::APosition³M(const Vector3M& pos)
    {
        if(!is_nan(pos))
            m_position  = pos;
    }

    APosition³M::APosition³M(const Param&p) : APosition³M(p.position)
    {
    }
    
    APosition³M::~APosition³M()
    {
    }

    void        APosition³M::position(emit_k)
    {
        send(new Position³MEvent({.source=typed()}, m_position));
    }

    void        APosition³M::position(set_k, const Vector3M& sz) 
    {
        if(is_nan(sz))
            return ;
            
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition³M::position(set_k, x_k, Meter v) 
    {
        position(SET, Vector3M(v, m_position.y, m_position.z));
    }
    
    void        APosition³M::position(set_k, y_k, Meter v) 
    {
        position(SET, Vector3M(m_position.x,v, m_position.z));
    }
    
    void        APosition³M::position(set_k, z_k, Meter v) 
    {
        position(SET, Vector3M(m_position.x, m_position.y, v));
    }
    
    void        APosition³M::position(add_k, const Vector3M&v) 
    {
        position(SET, Vector3M( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z ));
    }
    
    void        APosition³M::position(add_k, x_k, Meter v) 
    {
        position(SET, Vector3M( m_position.x+v, m_position.y, m_position.z ));
    }
    
    void        APosition³M::position(add_k, y_k, Meter v) 
    {
        position(SET, Vector3M( m_position.x, m_position.y+v, m_position.z ));
    }
    
    void        APosition³M::position(add_k, z_k, Meter v) 
    {
        position(SET, Vector3M( m_position.x, m_position.y, m_position.z+v ));
    }

    void        APosition³M::position(multiply_k, double v) 
    {
        position(SET, Vector3M( m_position.x*v, m_position.y*v, m_position.z*v ));
    }
    
    void        APosition³M::position(multiply_k, const Vector3D& v) 
    {
        position(SET, Vector3M( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z ));
    }
    
    void        APosition³M::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector3M( m_position.x*v, m_position.y, m_position.z ));
    }
    
    void        APosition³M::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector3M( m_position.x, m_position.y*v, m_position.z ));
    }
    
    void        APosition³M::position(multiply_k, z_k, double v)
    {
        position(SET, Vector3M( m_position.x, m_position.y, m_position.z*v ));
    }
    
    void        APosition³M::on_set_position3(const SetPosition³MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition³M::on_set_positionX(const SetPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition³M::on_set_positionY(const SetPositionʸMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition³M::on_set_positionZ(const SetPositionᶻMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition³M::on_add_position3(const AddPosition³MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition³M::on_add_positionX(const AddPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition³M::on_add_positionY(const AddPositionʸMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition³M::on_add_positionZ(const AddPositionᶻMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition³M::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³M::on_multiply_position3(const MultiplyPosition³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³M::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition³M::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition³M::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
