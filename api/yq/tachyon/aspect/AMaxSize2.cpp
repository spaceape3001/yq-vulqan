////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AMaxSize2.hpp>
#include <yq/tachyon/command/size/AddMaxSize2Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize2Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize2Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/event/spatial/Size2Event.hpp>


namespace yq::tachyon {
    AMaxSize²::AMaxSize²()
    {
    }
    
    AMaxSize²::~AMaxSize²()
    {
    }

    void        AMaxSize²::max_size(emit_k)
    {
        send(new Size²Event({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize²::max_size(set_k, const Size2D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize²::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size2D(v, m_max_size.y));
    }
    
    void        AMaxSize²::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size2D(m_max_size.x, v));
    }
    
    void        AMaxSize²::max_size(add_k, const Vector2D&v) 
    {
        max_size(SET, Size2D( m_max_size.x+v.x, m_max_size.y+v.y ));
    }
    
    void        AMaxSize²::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x+v, m_max_size.y ));
    }
    
    void        AMaxSize²::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x, m_max_size.y+v ));
    }

    void        AMaxSize²::max_size(multiply_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x*v, m_max_size.y*v ));
    }
    
    void        AMaxSize²::max_size(multiply_k, const Vector2D& v) 
    {
        max_size(SET, Size2D( m_max_size.x*v.x, m_max_size.y*v.y ));
    }
    
    void        AMaxSize²::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x*v, m_max_size.y ));
    }
    
    void        AMaxSize²::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x, m_max_size.y*v ));
    }
    
    void        AMaxSize²::on_set_max_size2(const SetMaxSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize²::on_set_max_sizeX(const SetMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize²::on_set_max_sizeY(const SetMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize²::on_add_max_size2(const AddMaxSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize²::on_add_max_sizeX(const AddMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize²::on_add_max_sizeY(const AddMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize²::on_multiply_max_size(const MultiplyMaxSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize²::on_multiply_max_size2(const MultiplyMaxSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize²::on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize²::on_multiply_max_sizeY(const MultiplyMaxSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
}
