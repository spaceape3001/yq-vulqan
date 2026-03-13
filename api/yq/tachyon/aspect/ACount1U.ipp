////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount1UWriter.hxx"

#include <yq/tachyon/command/count/AddCount1UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount1UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCount1UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/event/count/Count1UEvent.hpp>

namespace yq::tachyon {
    ACount¹U::ACount¹U(const Param& p) : m_count(p.count)
    {
    }

    ACount¹U::ACount¹U(const Vector1U& cnt) : m_count(cnt)
    {
        
    }
    
    ACount¹U::~ACount¹U()
    {
    }

    void        ACount¹U::count(emit_k)
    {
        send(new Count¹UEvent({.source=typed()}, m_count));
    }

    void        ACount¹U::count(set_k, const Vector1U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount¹U::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector1U(v));
    }
    
    void        ACount¹U::count(add_k, const Vector1U&v) 
    {
        count(SET, Vector1U( m_count.x+v.x ));
    }
    
    void        ACount¹U::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x+v ));
    }

    void        ACount¹U::count(multiply_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x*v ));
    }
    
    void        ACount¹U::count(multiply_k, const Vector1U& v) 
    {
        count(SET, Vector1U( m_count.x*v.x ));
    }
    
    void        ACount¹U::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector1U( m_count.x*v));
    }
    
    void        ACount¹U::on_set_count1(const SetCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount¹U::on_set_countX(const SetCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount¹U::on_add_count1(const AddCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount¹U::on_add_countX(const AddCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount¹U::on_multiply_count(const MultiplyCountUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount¹U::on_multiply_count1(const MultiplyCount¹UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount¹U::on_multiply_countX(const MultiplyCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
}
