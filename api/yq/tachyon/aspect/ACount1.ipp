////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount1Writer.hxx"

#include <yq/tachyon/command/count/AddCount1UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount1UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCount1UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/event/count/Count1UEvent.hpp>

namespace yq::tachyon {
    ACount¹::ACount¹(const Param& p) : m_count(p.count)
    {
    }

    ACount¹::ACount¹(const Vector1U& cnt) : m_count(cnt)
    {
        
    }
    
    ACount¹::~ACount¹()
    {
    }

    void        ACount¹::count(emit_k)
    {
        send(new Count¹UEvent({.source=typed()}, m_count));
    }

    void        ACount¹::count(set_k, const Vector1U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount¹::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector1U(v));
    }
    
    void        ACount¹::count(add_k, const Vector1U&v) 
    {
        count(SET, Vector1U( m_count.x+v.x ));
    }
    
    void        ACount¹::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x+v ));
    }

    void        ACount¹::count(multiply_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x*v ));
    }
    
    void        ACount¹::count(multiply_k, const Vector1U& v) 
    {
        count(SET, Vector1U( m_count.x*v.x ));
    }
    
    void        ACount¹::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x*v));
    }
    
    void        ACount¹::on_set_count1(const SetCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount¹::on_set_countX(const SetCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount¹::on_add_count1(const AddCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount¹::on_add_countX(const AddCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount¹::on_multiply_count(const MultiplyCountUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount¹::on_multiply_count1(const MultiplyCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount¹::on_multiply_countX(const MultiplyCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
}
