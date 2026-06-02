////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition1MWriter.hxx"
#include "APosition1M.hpp"
#include <yq/physicsvk/command/position/meter/AddPosition1MCommand.hpp>
#include <yq/physicsvk/command/position/meter/AddPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPosition1MCommand.hpp>
#include <yq/physicsvk/command/position/meter/SetPositionXMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/physicsvk/event/spatial/meter/Position1MEvent.hpp>

namespace yq::tachyon {
    APosition¹M::APosition¹M()
    {
        
    }
    
    APosition¹M::~APosition¹M()
    {
    }

    void        APosition¹M::position(emit_k)
    {
        send(new Position¹MEvent({.source=typed()}, m_position));
    }

    void        APosition¹M::position(set_k, const Vector1M& sz) 
    {
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition¹M::position(set_k, x_k, Meter v) 
    {
        position(SET, Vector1M(v));
    }
    
    void        APosition¹M::position(add_k, const Vector1M&v) 
    {
        position(SET, Vector1M( m_position.x+v.x ));
    }
    
    void        APosition¹M::position(add_k, x_k, Meter v) 
    {
        position(SET, Vector1M( m_position.x+v ));
    }

    void        APosition¹M::position(multiply_k, double v) 
    {
        position(SET, Vector1M( m_position.x*v ));
    }
    
    void        APosition¹M::position(multiply_k, const Vector1D& v) 
    {
        position(SET, Vector1M( m_position.x*v.x ));
    }
    
    void        APosition¹M::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector1M( m_position.x*v));
    }
    
    void        APosition¹M::on_set_position1(const SetPosition¹MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition¹M::on_set_positionX(const SetPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }
    
    void        APosition¹M::on_add_position1(const AddPosition¹MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition¹M::on_add_positionX(const AddPositionˣMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }
    
    void        APosition¹M::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹M::on_multiply_position1(const MultiplyPosition¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition¹M::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }
}
