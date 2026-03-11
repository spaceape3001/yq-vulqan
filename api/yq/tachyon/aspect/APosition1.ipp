////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/APosition1.hpp>
#include <yq/tachyon/command/position/AddPosition1DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPosition1DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/event/spatial/Position1DEvent.hpp>

namespace yq::tachyon {
    APosition¹::APosition¹()
    {
        
    }
    
    APosition¹::~APosition¹()
    {
    }

    void        APosition¹::position(emit_k)
    {
        send(new Position¹DEvent({.source=typed()}, m_position));
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
    
    void        APosition¹::on_set_position1(const SetPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition¹::on_set_positionX(const SetPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition¹::on_add_position1(const AddPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition¹::on_add_positionX(const AddPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition¹::on_multiply_position(const MultiplyPositionCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹::on_multiply_position1(const MultiplyPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
}
