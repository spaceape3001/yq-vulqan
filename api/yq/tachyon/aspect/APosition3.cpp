////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition3Writer.hxx"

#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/command/position/AddPosition3Command.hpp>
#include <yq/tachyon/command/position/AddPositionXCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <yq/tachyon/command/position/SetPosition3Command.hpp>
#include <yq/tachyon/command/position/SetPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZCommand.hpp>
#include <yq/tachyon/event/spatial/Position3Event.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    APosition³::APosition³()
    {
    }
    
    APosition³::~APosition³()
    {
    }

    void        APosition³::position(emit_k)
    {
        send(new Position³Event({.source=typed()}, m_position));
    }

    void        APosition³::position(set_k, const Vector3D& sz) 
    {
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
    
    void        APosition³::on_set_position3(const SetPosition³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition³::on_set_positionX(const SetPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition³::on_set_positionY(const SetPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition³::on_set_positionZ(const SetPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition³::on_add_position3(const AddPosition³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition³::on_add_positionX(const AddPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition³::on_add_positionY(const AddPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition³::on_add_positionZ(const AddPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition³::on_multiply_position(const MultiplyPositionCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_position3(const MultiplyPosition³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_positionX(const MultiplyPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition³::on_multiply_positionY(const MultiplyPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition³::on_multiply_positionZ(const MultiplyPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
