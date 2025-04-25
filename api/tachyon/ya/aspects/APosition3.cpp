////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition3Writer.hxx"

#include <ya/aspects/APosition3.hpp>
#include <tachyon/command/position/AddPosition3.hpp>
#include <tachyon/command/position/AddPositionX.hpp>
#include <tachyon/command/position/AddPositionY.hpp>
#include <tachyon/command/position/AddPositionZ.hpp>
#include <tachyon/command/position/MultiplyPosition.hpp>
#include <tachyon/command/position/MultiplyPosition3.hpp>
#include <tachyon/command/position/MultiplyPositionX.hpp>
#include <tachyon/command/position/MultiplyPositionY.hpp>
#include <tachyon/command/position/MultiplyPositionZ.hpp>
#include <tachyon/command/position/SetPosition3.hpp>
#include <tachyon/command/position/SetPositionX.hpp>
#include <tachyon/command/position/SetPositionY.hpp>
#include <tachyon/command/position/SetPositionZ.hpp>
#include <tachyon/event/spatial/Position3Event.hpp>
#include <yt/logging.hpp>
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
    
    void        APosition³::on_set_position3(const SetPosition³&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition³::on_set_positionX(const SetPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition³::on_set_positionY(const SetPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition³::on_set_positionZ(const SetPositionᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition³::on_add_position3(const AddPosition³&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition³::on_add_positionX(const AddPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition³::on_add_positionY(const AddPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition³::on_add_positionZ(const AddPositionᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition³::on_multiply_position(const MultiplyPosition&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_position3(const MultiplyPosition³&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition³::on_multiply_positionX(const MultiplyPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition³::on_multiply_positionY(const MultiplyPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition³::on_multiply_positionZ(const MultiplyPositionᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
