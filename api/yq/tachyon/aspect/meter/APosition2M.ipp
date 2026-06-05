////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition2MWriter.hxx"
#include "APosition2M.hpp"
#include <yq/tachyon/command/position/meter/AddPosition2MCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/AddPositionYMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPosition2MCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/meter/SetPositionYMCommand.hpp>
#include <yq/tachyon/event/spatial/meter/Position2MEvent.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>

namespace yq::tachyon {
    APosition²M::APosition²M(const Vector2M& pos)
    {
        if(!is_nan(pos))
            m_position  = pos;
    }
    
    APosition²M::~APosition²M()
    {
    }

    void        APosition²M::position(emit_k)
    {
        send(new Position²MEvent({.source=typed()}, m_position));
    }

    void        APosition²M::position(set_k, const Vector2M& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition²M::position(set_k, x_k, Meter v) 
    {
        position(SET, Vector2M(v, m_position.y));
    }
    
    void        APosition²M::position(set_k, y_k, Meter v) 
    {
        position(SET, Vector2M(m_position.x, v));
    }
    
    void        APosition²M::position(add_k, const Vector2M&v) 
    {
        position(SET, Vector2M( m_position.x+v.x, m_position.y+v.y ));
    }
    
    void        APosition²M::position(add_k, x_k, Meter v) 
    {
        position(SET, Vector2M( m_position.x+v, m_position.y ));
    }
    
    void        APosition²M::position(add_k, y_k, Meter v) 
    {
        position(SET, Vector2M( m_position.x, m_position.y+v ));
    }

    void        APosition²M::position(multiply_k, double v) 
    {
        position(SET, Vector2M( m_position.x*v, m_position.y*v ));
    }
    
    void        APosition²M::position(multiply_k, const Vector2D& v) 
    {
        position(SET, Vector2M( m_position.x*v.x, m_position.y*v.y ));
    }
    
    void        APosition²M::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector2M( m_position.x*v, m_position.y ));
    }
    
    void        APosition²M::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector2M( m_position.x, m_position.y*v ));
    }
    
    void        APosition²M::on_set_position2(const SetPosition²MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition²M::on_set_positionX(const SetPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition²M::on_set_positionY(const SetPositionʸMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition²M::on_add_position2(const AddPosition²MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition²M::on_add_positionX(const AddPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition²M::on_add_positionY(const AddPositionʸMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δy());
    }
    
    void        APosition²M::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²M::on_multiply_position2(const MultiplyPosition²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²M::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition²M::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
}
