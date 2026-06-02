////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition1CMWriter.hxx"
#include "APosition1CM.hpp"
#include <yq/physicsvk/command/position/centimeter/AddPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPosition1CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/physicsvk/event/spatial/centimeter/Position1CMEvent.hpp>

namespace yq::tachyon {
    APosition¹CM::APosition¹CM()
    {
        
    }
    
    APosition¹CM::~APosition¹CM()
    {
    }

    void        APosition¹CM::position(emit_k)
    {
        send(new Position¹CMEvent({.source=typed()}, m_position));
    }

    void        APosition¹CM::position(set_k, const Centimeter1D& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition¹CM::position(set_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter1D(v));
    }
    
    void        APosition¹CM::position(add_k, const Centimeter1D&v) 
    {
        position(SET, Centimeter1D( m_position.x+v.x ));
    }
    
    void        APosition¹CM::position(add_k, x_k, Centimeter v) 
    {
        position(SET, Centimeter1D( m_position.x+v ));
    }

    void        APosition¹CM::position(multiply_k, double v) 
    {
        position(SET, Centimeter1D( m_position.x*v ));
    }
    
    void        APosition¹CM::position(multiply_k, const Vector1D& v) 
    {
        position(SET, Centimeter1D( m_position.x*v.x ));
    }
    
    void        APosition¹CM::position(multiply_k, x_k, double v) 
    {
        position(SET, Centimeter1D( m_position.x*v));
    }
    
    void        APosition¹CM::on_set_position1(const SetPosition¹CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition¹CM::on_set_positionX(const SetPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition¹CM::on_add_position1(const AddPosition¹CMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition¹CM::on_add_positionX(const AddPositionˣCMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition¹CM::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹CM::on_multiply_position1(const MultiplyPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹CM::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
}
