////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/APosition2.hpp>
#include <yq/tachyon/command/position/AddPosition2Command.hpp>
#include <yq/tachyon/command/position/AddPositionXCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/SetPosition2Command.hpp>
#include <yq/tachyon/command/position/SetPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYCommand.hpp>
#include <yq/tachyon/event/spatial/Position2Event.hpp>

namespace yq::tachyon {
    APosition²::APosition²()
    {
    }
    
    APosition²::~APosition²()
    {
    }

    void        APosition²::position(emit_k)
    {
        send(new Position²Event({.source=typed()}, m_position));
    }

    void        APosition²::position(set_k, const Vector2D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition²::position(set_k, x_k, double v) 
    {
        position(SET, Vector2D(v, m_position.y));
    }
    
    void        APosition²::position(set_k, y_k, double v) 
    {
        position(SET, Vector2D(m_position.x, v));
    }
    
    void        APosition²::position(add_k, const Vector2D&v) 
    {
        position(SET, Vector2D( m_position.x+v.x, m_position.y+v.y ));
    }
    
    void        APosition²::position(add_k, x_k, double v) 
    {
        position(SET, Vector2D( m_position.x+v, m_position.y ));
    }
    
    void        APosition²::position(add_k, y_k, double v) 
    {
        position(SET, Vector2D( m_position.x, m_position.y+v ));
    }

    void        APosition²::position(multiply_k, double v) 
    {
        position(SET, Vector2D( m_position.x*v, m_position.y*v ));
    }
    
    void        APosition²::position(multiply_k, const Vector2D& v) 
    {
        position(SET, Vector2D( m_position.x*v.x, m_position.y*v.y ));
    }
    
    void        APosition²::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector2D( m_position.x*v, m_position.y ));
    }
    
    void        APosition²::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector2D( m_position.x, m_position.y*v ));
    }
    
    void        APosition²::on_set_position2(const SetPosition²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition²::on_set_positionX(const SetPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition²::on_set_positionY(const SetPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition²::on_add_position2(const AddPosition²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition²::on_add_positionX(const AddPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition²::on_add_positionY(const AddPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δy());
    }
    
    void        APosition²::on_multiply_position(const MultiplyPositionCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²::on_multiply_position2(const MultiplyPosition²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²::on_multiply_positionX(const MultiplyPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition²::on_multiply_positionY(const MultiplyPositionʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
}
