////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount4UWriter.hxx"

#include <yq/tachyon/aspect/ACount4U.hpp>
#include <yq/tachyon/command/count/AddCount4UCommand.hpp>
#include <yq/tachyon/command/count/AddCountWUCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount4UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountWUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount4UCommand.hpp>
#include <yq/tachyon/command/count/SetCountWUCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>
#include <yq/tachyon/event/count/Count4UEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector4.hxx>

namespace yq::tachyon {
    ACount⁴U::ACount⁴U(const Param&p) : m_count(p.count)
    {
    }

    ACount⁴U::ACount⁴U(const Vector4U& cnt) : m_count(cnt)
    {
    }
    
    ACount⁴U::~ACount⁴U()
    {
    }

    void        ACount⁴U::count(emit_k)
    {
        send(new Count⁴UEvent({.source=typed()}, m_count));
    }

    void        ACount⁴U::count(set_k, const Vector4U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount⁴U::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector4U(v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(set_k, y_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x,v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(set_k, z_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x, m_count.y, v, m_count.w ));
    }
    
    void        ACount⁴U::count(set_k, w_k, unsigned v) 
    {
        count(SET, Vector4U(m_count.x, m_count.y, m_count.z, v ));
    }

    void        ACount⁴U::count(add_k, const Vector4U&v) 
    {
        count(SET, Vector4U( m_count.x+v.x, m_count.y+v.y, m_count.z+v.z, m_count.w+v.w ));
    }
    
    void        ACount⁴U::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x+v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(add_k, y_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y+v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(add_k, z_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z+v, m_count.w ));
    }

    void        ACount⁴U::count(add_k, w_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z, m_count.w+v ));
    }

    void        ACount⁴U::count(multiply_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x*v, m_count.y*v, m_count.z*v, m_count.w*v ));
    }
    
    void        ACount⁴U::count(multiply_k, const Vector4U& v) 
    {
        count(SET, Vector4U( m_count.x*v.x, m_count.y*v.y, m_count.z*v.z, m_count.w*v.w ));
    }
    
    void        ACount⁴U::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x*v, m_count.y, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(multiply_k, y_k, unsigned v) 
    {
        count(SET, Vector4U( m_count.x, m_count.y*v, m_count.z, m_count.w ));
    }
    
    void        ACount⁴U::count(multiply_k, z_k, unsigned v)
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z*v, m_count.w ));
    }
    
    void        ACount⁴U::count(multiply_k, w_k, unsigned v)
    {
        count(SET, Vector4U( m_count.x, m_count.y, m_count.z, m_count.w*v ));
    }

    void        ACount⁴U::on_set_count4(const SetCount⁴UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount⁴U::on_set_countW(const SetCountʷUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, W, cmd.w());
    }
    
    void        ACount⁴U::on_set_countX(const SetCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }

    void        ACount⁴U::on_set_countY(const SetCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount⁴U::on_set_countZ(const SetCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Z, cmd.z());
    }

    void        ACount⁴U::on_add_count4(const AddCount⁴UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount⁴U::on_add_countW(const AddCountʷUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, W, cmd.Δw());
    }
    
    void        ACount⁴U::on_add_countX(const AddCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }

    void        ACount⁴U::on_add_countY(const AddCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Y, cmd.Δy());
    }
    
    void        ACount⁴U::on_add_countZ(const AddCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Z, cmd.Δz());
    }
    
    void        ACount⁴U::on_multiply_count(const MultiplyCountUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount⁴U::on_multiply_count4(const MultiplyCount⁴UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount⁴U::on_multiply_countW(const MultiplyCountʷUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, W, cmd.δw());
    }
    
    void        ACount⁴U::on_multiply_countX(const MultiplyCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }

    void        ACount⁴U::on_multiply_countY(const MultiplyCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
    
    void        ACount⁴U::on_multiply_countZ(const MultiplyCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Z, cmd.δz());
    }
}
