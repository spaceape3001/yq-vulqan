////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount2Writer.hxx"

#include <yq/tachyon/command/count/AddCount2Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount2Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCount2Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/event/count/Count2Event.hpp>

namespace yq::tachyon {
    ACount²::ACount²(const Param&p) : m_count(p.count)
    {
    }

    ACount²::ACount²(const Vector2U& cnt) : m_count(cnt)
    {
    }
    
    ACount²::~ACount²()
    {
    }

    void        ACount²::count(emit_k)
    {
        send(new Count²Event({.source=typed()}, m_count));
    }

    void        ACount²::count(set_k, const Vector2U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount²::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector2U(v, m_count.y));
    }
    
    void        ACount²::count(set_k, y_k, unsigned v) 
    {
        count(SET, Vector2U(m_count.x, v));
    }
    
    void        ACount²::count(add_k, const Vector2U&v) 
    {
        count(SET, Vector2U( m_count.x+v.x, m_count.y+v.y ));
    }
    
    void        ACount²::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector2U( m_count.x+v, m_count.y ));
    }
    
    void        ACount²::count(add_k, y_k, unsigned v) 
    {
        count(SET, Vector2U( m_count.x, m_count.y+v ));
    }

    void        ACount²::count(multiply_k, unsigned v) 
    {
        count(SET, Vector2U( m_count.x*v, m_count.y*v ));
    }
    
    void        ACount²::count(multiply_k, const Vector2U& v) 
    {
        count(SET, Vector2U( m_count.x*v.x, m_count.y*v.y ));
    }
    
    void        ACount²::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector2U( m_count.x*v, m_count.y ));
    }
    
    void        ACount²::count(multiply_k, y_k, unsigned v) 
    {
        count(SET, Vector2U( m_count.x, m_count.y*v ));
    }
    
    void        ACount²::on_set_count2(const SetCount²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount²::on_set_countX(const SetCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount²::on_set_countY(const SetCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount²::on_add_count2(const AddCount²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount²::on_add_countX(const AddCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount²::on_add_countY(const AddCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δy());
    }
    
    void        ACount²::on_multiply_count(const MultiplyCountCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount²::on_multiply_count2(const MultiplyCount²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount²::on_multiply_countX(const MultiplyCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
    
    void        ACount²::on_multiply_countY(const MultiplyCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
}
