////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount2Writer.hxx"

#include <yq/tachyon/command/count/AddCount2UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount2UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCount2UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/event/count/Count2UEvent.hpp>

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
        send(new Count²UEvent({.source=typed()}, m_count));
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
    
    void        ACount²::on_set_count2(const SetCount²UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount²::on_set_countX(const SetCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount²::on_set_countY(const SetCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount²::on_add_count2(const AddCount²UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount²::on_add_countX(const AddCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount²::on_add_countY(const AddCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δy());
    }
    
    void        ACount²::on_multiply_count(const MultiplyCountUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount²::on_multiply_count2(const MultiplyCount²UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount²::on_multiply_countX(const MultiplyCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
    
    void        ACount²::on_multiply_countY(const MultiplyCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
}
