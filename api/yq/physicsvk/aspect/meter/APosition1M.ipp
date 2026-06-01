////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/APosition1D.hpp>
#include <yq/tachyon/command/position/AddPosition1DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition1DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/event/spatial/Position1DEvent.hpp>

namespace yq::tachyon {
    APosition¹D::APosition¹D()
    {
        
    }
    
    APosition¹D::~APosition¹D()
    {
    }

    void        APosition¹D::position(emit_k)
    {
        send(new Position¹DEvent({.source=typed()}, m_position));
    }

    void        APosition¹D::position(set_k, const Vector1D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition¹D::position(set_k, x_k, double v) 
    {
        position(SET, Vector1D(v));
    }
    
    void        APosition¹D::position(add_k, const Vector1D&v) 
    {
        position(SET, Vector1D( m_position.x+v.x ));
    }
    
    void        APosition¹D::position(add_k, x_k, double v) 
    {
        position(SET, Vector1D( m_position.x+v ));
    }

    void        APosition¹D::position(multiply_k, double v) 
    {
        position(SET, Vector1D( m_position.x*v ));
    }
    
    void        APosition¹D::position(multiply_k, const Vector1D& v) 
    {
        position(SET, Vector1D( m_position.x*v.x ));
    }
    
    void        APosition¹D::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector1D( m_position.x*v));
    }
    
    void        APosition¹D::on_set_position1(const SetPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition¹D::on_set_positionX(const SetPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition¹D::on_add_position1(const AddPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition¹D::on_add_positionX(const AddPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition¹D::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹D::on_multiply_position1(const MultiplyPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹D::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
}
