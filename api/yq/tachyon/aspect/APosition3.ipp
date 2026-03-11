////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition3Writer.hxx"

#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/command/position/AddPosition3DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition3DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZDCommand.hpp>
#include <yq/tachyon/event/spatial/Position3DEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    APosition³::APosition³(const Vector3D& pos)
    {
        if(!is_nan(pos))
            m_position  = pos;
    }

    APosition³::APosition³(const Param&p) : APosition³(p.position)
    {
    }
    
    APosition³::~APosition³()
    {
    }

    void        APosition³::position(emit_k)
    {
        send(new Position³DEvent({.source=typed()}, m_position));
    }

    void        APosition³::position(set_k, const Vector3D& sz) 
    {
        if(is_nan(sz))
            return ;
            
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition³::position(set_k, x_k, double v) 
    {
        position(SET, Vector3D(v, m_position.y, m_position.z));
    }
    
    void        APosition³::position(set_k, y_k, double v) 
    {
        position(SET, Vector3D(m_position.x,v, m_position.z));
    }
    
    void        APosition³::position(set_k, z_k, double v) 
    {
        position(SET, Vector3D(m_position.x, m_position.y, v));
    }
    
    void        APosition³::position(add_k, const Vector3D&v) 
    {
        position(SET, Vector3D( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z ));
    }
    
    void        APosition³::position(add_k, x_k, double v) 
    {
        position(SET, Vector3D( m_position.x+v, m_position.y, m_position.z ));
    }
    
    void        APosition³::position(add_k, y_k, double v) 
    {
        position(SET, Vector3D( m_position.x, m_position.y+v, m_position.z ));
    }
    
    void        APosition³::position(add_k, z_k, double v) 
    {
        position(SET, Vector3D( m_position.x, m_position.y, m_position.z+v ));
    }

    void        APosition³::position(multiply_k, double v) 
    {
        position(SET, Vector3D( m_position.x*v, m_position.y*v, m_position.z*v ));
    }
    
    void        APosition³::position(multiply_k, const Vector3D& v) 
    {
        position(SET, Vector3D( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z ));
    }
    
    void        APosition³::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector3D( m_position.x*v, m_position.y, m_position.z ));
    }
    
    void        APosition³::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector3D( m_position.x, m_position.y*v, m_position.z ));
    }
    
    void        APosition³::position(multiply_k, z_k, double v)
    {
        position(SET, Vector3D( m_position.x, m_position.y, m_position.z*v ));
    }
    
    void        APosition³::on_set_position3(const SetPosition³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition³::on_set_positionX(const SetPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition³::on_set_positionY(const SetPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition³::on_set_positionZ(const SetPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition³::on_add_position3(const AddPosition³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition³::on_add_positionX(const AddPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition³::on_add_positionY(const AddPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition³::on_add_positionZ(const AddPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition³::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_position3(const MultiplyPosition³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition³::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition³::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
