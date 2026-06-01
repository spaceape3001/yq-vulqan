////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "APosition4MWriter.hxx"

#include "APosition4M.hpp"
#include <yq/physicsvk/command/position/AddPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/AddPositionZMCommand.hpp>
#include <yq/physicsvk/command/position/SetPosition4MCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionWMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionXMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionYMCommand.hpp>
#include <yq/physicsvk/command/position/SetPositionZMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/event/spatial/Position4DEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    APosition⁴M::APosition⁴M(const Vector4M& pos) 
    {
        if(!is_nan(pos))
            m_position = pos;
    }
    
    APosition⁴M::~APosition⁴M()
    {
    }

    void        APosition⁴M::position(emit_k)
    {
        send(new Position⁴MEvent({.source=typed()}, m_position));
    }

    void        APosition⁴M::position(set_k, const Vector4M& sz) 
    {
        if(is_nan(sz))
            return;
            
        m_position  =    sz;
        mark();
        position(EMIT);
    }
    
    void        APosition⁴M::position(set_k, x_k, double v) 
    {
        position(SET, Vector4M(v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(set_k, y_k, double v) 
    {
        position(SET, Vector4M(m_position.x,v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(set_k, z_k, double v) 
    {
        position(SET, Vector4M(m_position.x, m_position.y, v, m_position.w ));
    }
    
    void        APosition⁴M::position(set_k, w_k, double v) 
    {
        position(SET, Vector4M(m_position.x, m_position.y, m_position.z, v ));
    }

    void        APosition⁴M::position(add_k, const Vector4M&v) 
    {
        position(SET, Vector4M( m_position.x+v.x, m_position.y+v.y, m_position.z+v.z, m_position.w+v.w ));
    }
    
    void        APosition⁴M::position(add_k, x_k, double v) 
    {
        position(SET, Vector4M( m_position.x+v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(add_k, y_k, double v) 
    {
        position(SET, Vector4M( m_position.x, m_position.y+v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(add_k, z_k, double v) 
    {
        position(SET, Vector4M( m_position.x, m_position.y, m_position.z+v, m_position.w ));
    }

    void        APosition⁴M::position(add_k, w_k, double v) 
    {
        position(SET, Vector4M( m_position.x, m_position.y, m_position.z, m_position.w+v ));
    }

    void        APosition⁴M::position(multiply_k, double v) 
    {
        position(SET, Vector4M( m_position.x*v, m_position.y*v, m_position.z*v, m_position.w*v ));
    }
    
    void        APosition⁴M::position(multiply_k, const Vector4M& v) 
    {
        position(SET, Vector4M( m_position.x*v.x, m_position.y*v.y, m_position.z*v.z, m_position.w*v.w ));
    }
    
    void        APosition⁴M::position(multiply_k, x_k, double v) 
    {
        position(SET, Vector4M( m_position.x*v, m_position.y, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(multiply_k, y_k, double v) 
    {
        position(SET, Vector4M( m_position.x, m_position.y*v, m_position.z, m_position.w ));
    }
    
    void        APosition⁴M::position(multiply_k, z_k, double v)
    {
        position(SET, Vector4M( m_position.x, m_position.y, m_position.z*v, m_position.w ));
    }
    
    void        APosition⁴M::position(multiply_k, w_k, double v)
    {
        position(SET, Vector4M( m_position.x, m_position.y, m_position.z, m_position.w*v ));
    }

    void        APosition⁴M::on_set_position4(const SetPosition⁴MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, cmd.position());
    }
    
    void        APosition⁴M::on_set_positionW(const SetPositionʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, W, cmd.w());
    }
    
    void        APosition⁴M::on_set_positionX(const SetPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, X, cmd.x());
    }

    void        APosition⁴M::on_set_positionY(const SetPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Y, cmd.y());
    }
    
    void        APosition⁴M::on_set_positionZ(const SetPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(SET, Z, cmd.z());
    }

    void        APosition⁴M::on_add_position4(const AddPosition⁴MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, cmd.Δ());
    }
    
    void        APosition⁴M::on_add_positionW(const AddPositionʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, W, cmd.Δw());
    }
    
    void        APosition⁴M::on_add_positionX(const AddPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, X, cmd.Δx());
    }

    void        APosition⁴M::on_add_positionY(const AddPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Y, cmd.Δy());
    }
    
    void        APosition⁴M::on_add_positionZ(const AddPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(ADD, Z, cmd.Δz());
    }
    
    void        APosition⁴M::on_multiply_position(const MultiplyPositionDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴M::on_multiply_position4(const MultiplyPosition⁴MCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, cmd.δ());
    }
    
    void        APosition⁴M::on_multiply_positionW(const MultiplyPositionʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, W, cmd.δw());
    }
    
    void        APosition⁴M::on_multiply_positionX(const MultiplyPositionˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, X, cmd.δx());
    }

    void        APosition⁴M::on_multiply_positionY(const MultiplyPositionʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Y, cmd.δy());
    }
    
    void        APosition⁴M::on_multiply_positionZ(const MultiplyPositionᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        position(MULTIPLY, Z, cmd.δz());
    }
}
