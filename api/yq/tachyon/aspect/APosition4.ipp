////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition4Writer.hxx"

#include <yq/tachyon/aspect/APosition4.hpp>
#include <yq/tachyon/command/position/AddPosition4DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionWDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <yq/tachyon/command/position/SetPosition4DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionWDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZDCommand.hpp>
#include <yq/tachyon/event/spatial/Position4DEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    APosition⁴::APosition⁴(const Vector4D& pos) 
    {
        if(!is_nan(pos))
            m_position = pos;
    }
    
    APosition⁴::~APosition⁴()
    {
    }

    void        APosition⁴::position(emit_k)
    {
        send(new Position⁴DEvent({.source=typed()}, m_position));
    }

    void        APosition⁴::position(set_k, const Vector4D& sz) 
    {
        if(is_nan(sz))
            return;
            
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

    void        APosition⁴::on_set_position4(const SetPosition⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition⁴::on_set_positionW(const SetPositionʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, W, cmd.w());
    }
    
    void        APosition⁴::on_set_positionX(const SetPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }

    void        APosition⁴::on_set_positionY(const SetPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition⁴::on_set_positionZ(const SetPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition⁴::on_add_position4(const AddPosition⁴DCommand&cmd)
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
    
    void        APosition⁴::on_add_positionX(const AddPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }

    void        APosition⁴::on_add_positionY(const AddPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition⁴::on_add_positionZ(const AddPositionᶻDCommand&cmd)
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
    
    void        APosition⁴::on_multiply_position4(const MultiplyPosition⁴DCommand&cmd)
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
    
    void        APosition⁴::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }

    void        APosition⁴::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition⁴::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
