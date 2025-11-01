////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition4Writer.hxx"

#include <tachyon/aspect/APosition4.hpp>
#include <tachyon/command/position/AddPosition4Command.hpp>
#include <tachyon/command/position/AddPositionWCommand.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/AddPositionZCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition4Command.hpp>
#include <tachyon/command/position/MultiplyPositionWCommand.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <tachyon/command/position/SetPosition4Command.hpp>
#include <tachyon/command/position/SetPositionWCommand.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/command/position/SetPositionZCommand.hpp>
#include <tachyon/event/spatial/Position4Event.hpp>
#include <tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    APosition⁴::APosition⁴()
    {
    }
    
    APosition⁴::~APosition⁴()
    {
    }

    void        APosition⁴::position(emit_k)
    {
        send(new Position⁴Event({.source=typed()}, m_position));
    }

    void        APosition⁴::position(set_k, const Vector4D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition⁴::position(set_k, x_k, double v) 
    {
        position(SET, Vector4D(v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(set_k, y_k, double v) 
    {
        position(SET, Vector4D(m_position.x,v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(set_k, z_k, double v) 
    {
        position(SET, Vector4D(m_position.x, m_position.y, v, m_position.w ));
    }
    
    void        APosition⁴::position(set_k, w_k, double v) 
    {
        position(SET, Vector4D(m_position.x, m_position.y, m_position.z, v ));
    }

    void        APosition⁴::position(add_k, const Vector4D&v) 
    {
        position(SET, Vector4D( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z, m_position.w+v.w ));
    }
    
    void        APosition⁴::position(add_k, x_k, double v) 
    {
        position(SET, Vector4D( m_position.x+v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(add_k, y_k, double v) 
    {
        position(SET, Vector4D( m_position.x, m_position.y+v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(add_k, z_k, double v) 
    {
        position(SET, Vector4D( m_position.x, m_position.y, m_position.z+v, m_position.w ));
    }

    void        APosition⁴::position(add_k, w_k, double v) 
    {
        position(SET, Vector4D( m_position.x, m_position.y, m_position.z, m_position.w+v ));
    }

    void        APosition⁴::position(multiply_k, double v) 
    {
        position(SET, Vector4D( m_position.x*v, m_position.y*v, m_position.z*v, m_position.w*v ));
    }
    
    void        APosition⁴::position(multiply_k, const Vector4D& v) 
    {
        position(SET, Vector4D( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z, m_position.w*v.w ));
    }
    
    void        APosition⁴::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector4D( m_position.x*v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector4D( m_position.x, m_position.y*v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴::position(multiply_k, z_k, double v)
    {
        position(SET, Vector4D( m_position.x, m_position.y, m_position.z*v, m_position.w ));
    }
    
    void        APosition⁴::position(multiply_k, w_k, double v)
    {
        position(SET, Vector4D( m_position.x, m_position.y, m_position.z, m_position.w*v ));
    }

    void        APosition⁴::on_set_position4(const SetPosition⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition⁴::on_set_positionW(const SetPositionʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, W, cmd.w());
    }
    
    void        APosition⁴::on_set_positionX(const SetPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }

    void        APosition⁴::on_set_positionY(const SetPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition⁴::on_set_positionZ(const SetPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition⁴::on_add_position4(const AddPosition⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition⁴::on_add_positionW(const AddPositionʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, W, cmd.Δw());
    }
    
    void        APosition⁴::on_add_positionX(const AddPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }

    void        APosition⁴::on_add_positionY(const AddPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition⁴::on_add_positionZ(const AddPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition⁴::on_multiply_position(const MultiplyPositionCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴::on_multiply_position4(const MultiplyPosition⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴::on_multiply_positionW(const MultiplyPositionʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, W, cmd.δw());
    }
    
    void        APosition⁴::on_multiply_positionX(const MultiplyPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }

    void        APosition⁴::on_multiply_positionY(const MultiplyPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition⁴::on_multiply_positionZ(const MultiplyPositionᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
