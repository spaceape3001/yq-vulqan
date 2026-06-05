////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition2CMWriter.hxx"
#include "APosition2CM.hpp"
#include <yq/tachyon/command/position/centimeter/AddPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/event/spatial/centimeter/Position2CMEvent.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>

namespace yq::tachyon {
    APosition²CM::APosition²CM(const Centimeter2D& pos)
    {
        if(!is_nan(pos))
            m_position  = pos;
    }
    
    APosition²CM::~APosition²CM()
    {
    }

    void        APosition²CM::position(emit_k)
    {
        send(new Position²CMEvent({.source=typed()}, m_position));
    }

    void        APosition²CM::position(set_k, const Centimeter2D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition²CM::position(set_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter2D(v, m_position.y));
    }
    
    void        APosition²CM::position(set_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter2D(m_position.x, v));
    }
    
    void        APosition²CM::position(add_k, const Centimeter2D&v) 
    {
        position(SET, Centimeter2D( m_position.x+v.x, m_position.y+v.y ));
    }
    
    void        APosition²CM::position(add_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter2D( m_position.x+v, m_position.y ));
    }
    
    void        APosition²CM::position(add_k, y_k, Centimeter v) 
    {
        position(SET, Centimeter2D( m_position.x, m_position.y+v ));
    }

    void        APosition²CM::position(multiply_k, double v) 
    {
        position(SET, Centimeter2D( m_position.x*v, m_position.y*v ));
    }
    
    void        APosition²CM::position(multiply_k, const Vector2D& v) 
    {
        position(SET, Centimeter2D( m_position.x*v.x, m_position.y*v.y ));
    }
    
    void        APosition²CM::position(multiply_k, x_k, double v) 
    {
        position(SET, Centimeter2D( m_position.x*v, m_position.y ));
    }
    
    void        APosition²CM::position(multiply_k, y_k, double v) 
    {
        position(SET, Centimeter2D( m_position.x, m_position.y*v ));
    }
    
    void        APosition²CM::on_set_position2(const SetPosition²CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition²CM::on_set_positionX(const SetPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition²CM::on_set_positionY(const SetPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition²CM::on_add_position2(const AddPosition²CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition²CM::on_add_positionX(const AddPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition²CM::on_add_positionY(const AddPositionʸCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δy());
    }
    
    void        APosition²CM::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²CM::on_multiply_position2(const MultiplyPosition²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition²CM::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
    
    void        APosition²CM::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
}
