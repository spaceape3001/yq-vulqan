////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount3UWriter.hxx"

#include <yq/tachyon/aspect/ACount3U.hpp>
#include <yq/tachyon/command/count/AddCount3UCommand.hpp>
#include <yq/tachyon/command/count/AddCountXUCommand.hpp>
#include <yq/tachyon/command/count/AddCountYUCommand.hpp>
#include <yq/tachyon/command/count/AddCountZUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3UCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountXUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYUCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZUCommand.hpp>
#include <yq/tachyon/command/count/SetCount3UCommand.hpp>
#include <yq/tachyon/command/count/SetCountXUCommand.hpp>
#include <yq/tachyon/command/count/SetCountYUCommand.hpp>
#include <yq/tachyon/command/count/SetCountZUCommand.hpp>
#include <yq/tachyon/event/count/Count3UEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    ACount³U::ACount³U(const Param&p) : m_count(p.count)
    {
    }

    ACount³U::ACount³U(const Vector3U& c) : m_count(c)
    {
    }
    
    ACount³U::~ACount³U()
    {
    }

    void        ACount³U::count(emit_k)
    {
        send(new Count³UEvent({.source=typed()}, m_count));
    }

    void        ACount³U::count(set_k, const Vector3U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount³U::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector3U(v, m_count.y, m_count.z));
    }
    
    void        ACount³U::count(set_k, y_k, unsigned v) 
    {
        count(SET, Vector3U(m_count.x,v, m_count.z));
    }
    
    void        ACount³U::count(set_k, z_k, unsigned v) 
    {
        count(SET, Vector3U(m_count.x, m_count.y, v));
    }
    
    void        ACount³U::count(add_k, const Vector3U&v) 
    {
        count(SET, Vector3U( m_count.x+v.x, m_count.y+v.y, m_count.z+v.z ));
    }
    
    void        ACount³U::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x+v, m_count.y, m_count.z ));
    }
    
    void        ACount³U::count(add_k, y_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y+v, m_count.z ));
    }
    
    void        ACount³U::count(add_k, z_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y, m_count.z+v ));
    }

    void        ACount³U::count(multiply_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x*v, m_count.y*v, m_count.z*v ));
    }
    
    void        ACount³U::count(multiply_k, const Vector3U& v) 
    {
        count(SET, Vector3U( m_count.x*v.x, m_count.y*v.y, m_count.z*v.z ));
    }
    
    void        ACount³U::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x*v, m_count.y, m_count.z ));
    }
    
    void        ACount³U::count(multiply_k, y_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y*v, m_count.z ));
    }
    
    void        ACount³U::count(multiply_k, z_k, unsigned v)
    {
        count(SET, Vector3U( m_count.x, m_count.y, m_count.z*v ));
    }
    
    void        ACount³U::on_set_count3(const SetCount³UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount³U::on_set_countX(const SetCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount³U::on_set_countY(const SetCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount³U::on_set_countZ(const SetCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Z, cmd.z());
    }

    void        ACount³U::on_add_count3(const AddCount³UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount³U::on_add_countX(const AddCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount³U::on_add_countY(const AddCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Y, cmd.Δy());
    }
    
    void        ACount³U::on_add_countZ(const AddCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Z, cmd.Δz());
    }
    
    void        ACount³U::on_multiply_count(const MultiplyCountUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount³U::on_multiply_count3(const MultiplyCount³UCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount³U::on_multiply_countX(const MultiplyCountˣUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
    
    void        ACount³U::on_multiply_countY(const MultiplyCountʸUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
    
    void        ACount³U::on_multiply_countZ(const MultiplyCountᶻUCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Z, cmd.δz());
    }
}
