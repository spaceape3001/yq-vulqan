////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount4Writer.hxx"

#include <yq/tachyon/aspect/ACount4.hpp>
#include <yq/tachyon/command/count/AddCount4Command.hpp>
#include <yq/tachyon/command/count/AddCountWCommand.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/AddCountZCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount4Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountWCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZCommand.hpp>
#include <yq/tachyon/command/count/SetCount4Command.hpp>
#include <yq/tachyon/command/count/SetCountWCommand.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCountZCommand.hpp>
#include <yq/tachyon/event/count/Count4Event.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    ACount⁴::ACount⁴(const Vector4U& cnt) : m_count(cnt)
    {
    }
    
    ACount⁴::~ACount⁴()
    {
    }

    void        ACount⁴::count(emit_k)
    {
        send(new Count⁴Event({.source=typed()}, m_count));
    }

    void        ACount⁴::count(set_k, const Vector4U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount⁴::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector4U(v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(set_k, y_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x,v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(set_k, z_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x, m_count.y, v, m_count.w ));
    }
    
    void        ACount⁴::count(set_k, w_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x, m_count.y, m_count.z, v ));
    }

    void        ACount⁴::count(add_k, const Vector4U&v) 
    {
        count(SET, Vector4U( m_count.x+v.x, m_count.y+v.y, m_count.z+v.z, m_count.w+v.w ));
    }
    
    void        ACount⁴::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x+v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(add_k, y_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y+v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(add_k, z_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z+v, m_count.w ));
    }

    void        ACount⁴::count(add_k, w_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z, m_count.w+v ));
    }

    void        ACount⁴::count(multiply_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x*v, m_count.y*v, m_count.z*v, m_count.w*v ));
    }
    
    void        ACount⁴::count(multiply_k, const Vector4U& v) 
    {
        count(SET, Vector4U( m_count.x*v.x, m_count.y*v.y, m_count.z*v.z, m_count.w*v.w ));
    }
    
    void        ACount⁴::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x*v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(multiply_k, y_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y*v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴::count(multiply_k, z_k, unsigned v)
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z*v, m_count.w ));
    }
    
    void        ACount⁴::count(multiply_k, w_k, unsigned v)
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z, m_count.w*v ));
    }

    void        ACount⁴::on_set_count4(const SetCount⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount⁴::on_set_countW(const SetCountʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, W, cmd.w());
    }
    
    void        ACount⁴::on_set_countX(const SetCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }

    void        ACount⁴::on_set_countY(const SetCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount⁴::on_set_countZ(const SetCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Z, cmd.z());
    }

    void        ACount⁴::on_add_count4(const AddCount⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount⁴::on_add_countW(const AddCountʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, W, cmd.Δw());
    }
    
    void        ACount⁴::on_add_countX(const AddCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }

    void        ACount⁴::on_add_countY(const AddCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Y, cmd.Δy());
    }
    
    void        ACount⁴::on_add_countZ(const AddCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Z, cmd.Δz());
    }
    
    void        ACount⁴::on_multiply_count(const MultiplyCountCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount⁴::on_multiply_count4(const MultiplyCount⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount⁴::on_multiply_countW(const MultiplyCountʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, W, cmd.δw());
    }
    
    void        ACount⁴::on_multiply_countX(const MultiplyCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }

    void        ACount⁴::on_multiply_countY(const MultiplyCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
    
    void        ACount⁴::on_multiply_countZ(const MultiplyCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Z, cmd.δz());
    }
}
