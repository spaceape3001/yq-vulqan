////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/APosition2.hpp>
#include <ya/commands/spatial/AddPosition2.hpp>
#include <ya/commands/spatial/AddPositionX.hpp>
#include <ya/commands/spatial/AddPositionY.hpp>
#include <ya/commands/spatial/MultiplyPosition.hpp>
#include <ya/commands/spatial/MultiplyPosition2.hpp>
#include <ya/commands/spatial/MultiplyPositionX.hpp>
#include <ya/commands/spatial/MultiplyPositionY.hpp>
#include <ya/commands/spatial/SetPosition2.hpp>
#include <ya/commands/spatial/SetPositionX.hpp>
#include <ya/commands/spatial/SetPositionY.hpp>
#include <ya/events/spatial/Position2Event.hpp>

#include "APosition2Writer.hxx"

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
    
    void        APosition²::on_set_position2(const SetPosition²&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition²::on_set_positionX(const SetPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition²::on_set_positionY(const SetPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition²::on_add_position2(const AddPosition²&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition²::on_add_positionX(const AddPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition²::on_add_positionY(const AddPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δy());
    }
    
    void        APosition²::on_multiply_position(const MultiplyPosition&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²::on_multiply_position2(const MultiplyPosition²&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²::on_multiply_positionX(const MultiplyPositionˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition²::on_multiply_positionY(const MultiplyPositionʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
}
