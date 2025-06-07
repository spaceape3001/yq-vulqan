////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/APosition1.hpp>
#include <tachyon/command/position/AddPosition1Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition1Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/SetPosition1Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/event/spatial/Position1Event.hpp>

namespace yq::tachyon {
    APosition¹::APosition¹()
    {
        
    }
    
    APosition¹::~APosition¹()
    {
    }

    void        APosition¹::position(emit_k)
    {
        send(new Position¹Event({.source=typed()}, m_position));
    }

    void        APosition¹::position(set_k, const Vector1D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition¹::position(set_k, x_k, double v) 
    {
        position(SET, Vector1D(v));
    }
    
    void        APosition¹::position(add_k, const Vector1D&v) 
    {
        position(SET, Vector1D( m_position.x+v.x ));
    }
    
    void        APosition¹::position(add_k, x_k, double v) 
    {
        position(SET, Vector1D( m_position.x+v ));
    }

    void        APosition¹::position(multiply_k, double v) 
    {
        position(SET, Vector1D( m_position.x*v ));
    }
    
    void        APosition¹::position(multiply_k, const Vector1D& v) 
    {
        position(SET, Vector1D( m_position.x*v.x ));
    }
    
    void        APosition¹::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector1D( m_position.x*v));
    }
    
    void        APosition¹::on_set_position1(const SetPosition¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition¹::on_set_positionX(const SetPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition¹::on_add_position1(const AddPosition¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition¹::on_add_positionX(const AddPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition¹::on_multiply_position(const MultiplyPosition&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹::on_multiply_position1(const MultiplyPosition¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹::on_multiply_positionX(const MultiplyPositionˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
}
