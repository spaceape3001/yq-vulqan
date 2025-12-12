////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ACount3Writer.hxx"

#include <yq/tachyon/aspect/ACount3.hpp>
#include <yq/tachyon/command/count/AddCount3Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/AddCountZCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZCommand.hpp>
#include <yq/tachyon/command/count/SetCount3Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCountZCommand.hpp>
#include <yq/tachyon/event/count/Count3Event.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    ACount³::ACount³(const Vector3U& c) : m_count(c)
    {
    }
    
    ACount³::~ACount³()
    {
    }

    void        ACount³::count(emit_k)
    {
        send(new Count³Event({.source=typed()}, m_count));
    }

    void        ACount³::count(set_k, const Vector3U& sz) 
    {
        m_count  =    sz;
        mark();
        count(EMIT);
    }
    
    void        ACount³::count(set_k, x_k, unsigned v) 
    {
        count(SET, Vector3U(v, m_count.y, m_count.z));
    }
    
    void        ACount³::count(set_k, y_k, unsigned v) 
    {
        count(SET, Vector3U(m_count.x,v, m_count.z));
    }
    
    void        ACount³::count(set_k, z_k, unsigned v) 
    {
        count(SET, Vector3U(m_count.x, m_count.y, v));
    }
    
    void        ACount³::count(add_k, const Vector3U&v) 
    {
        count(SET, Vector3U( m_count.x+v.x, m_count.y+v.y, m_count.z+v.z ));
    }
    
    void        ACount³::count(add_k, x_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x+v, m_count.y, m_count.z ));
    }
    
    void        ACount³::count(add_k, y_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y+v, m_count.z ));
    }
    
    void        ACount³::count(add_k, z_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y, m_count.z+v ));
    }

    void        ACount³::count(multiply_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x*v, m_count.y*v, m_count.z*v ));
    }
    
    void        ACount³::count(multiply_k, const Vector3U& v) 
    {
        count(SET, Vector3U( m_count.x*v.x, m_count.y*v.y, m_count.z*v.z ));
    }
    
    void        ACount³::count(multiply_k, x_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x*v, m_count.y, m_count.z ));
    }
    
    void        ACount³::count(multiply_k, y_k, unsigned v) 
    {
        count(SET, Vector3U( m_count.x, m_count.y*v, m_count.z ));
    }
    
    void        ACount³::count(multiply_k, z_k, unsigned v)
    {
        count(SET, Vector3U( m_count.x, m_count.y, m_count.z*v ));
    }
    
    void        ACount³::on_set_count3(const SetCount³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, cmd.count());
    }
    
    void        ACount³::on_set_countX(const SetCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, X, cmd.x());
    }
    
    void        ACount³::on_set_countY(const SetCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Y, cmd.y());
    }
    
    void        ACount³::on_set_countZ(const SetCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(SET, Z, cmd.z());
    }

    void        ACount³::on_add_count3(const AddCount³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, cmd.Δ());
    }
    
    void        ACount³::on_add_countX(const AddCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, X, cmd.Δx());
    }
    
    void        ACount³::on_add_countY(const AddCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Y, cmd.Δy());
    }
    
    void        ACount³::on_add_countZ(const AddCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(ADD, Z, cmd.Δz());
    }
    
    void        ACount³::on_multiply_count(const MultiplyCountCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount³::on_multiply_count3(const MultiplyCount³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, cmd.δ());
    }
    
    void        ACount³::on_multiply_countX(const MultiplyCountˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, X, cmd.δx());
    }
    
    void        ACount³::on_multiply_countY(const MultiplyCountʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Y, cmd.δy());
    }
    
    void        ACount³::on_multiply_countZ(const MultiplyCountᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        count(MULTIPLY, Z, cmd.δz());
    }
}
