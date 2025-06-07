////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/AMinSize2.hpp>
#include <tachyon/command/size/AddMinSize2Command.hpp>
#include <tachyon/command/size/AddMinSizeXCommand.hpp>
#include <tachyon/command/size/AddMinSizeYCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMinSize2Command.hpp>
#include <tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <tachyon/command/size/SetMinSize2Command.hpp>
#include <tachyon/command/size/SetMinSizeXCommand.hpp>
#include <tachyon/command/size/SetMinSizeYCommand.hpp>
#include <tachyon/event/spatial/Size2Event.hpp>


namespace yq::tachyon {
    AMinSize²::AMinSize²()
    {
    }
    
    AMinSize²::~AMinSize²()
    {
    }

    void        AMinSize²::min_size(emit_k)
    {
        send(new Size²Event({.source=typed()}, m_min_size));
    }
    
    void        AMinSize²::min_size(set_k, const Size2D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize²::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size2D(v, m_min_size.y));
    }
    
    void        AMinSize²::min_size(set_k, y_k, double v) 
    {
        min_size(SET, Size2D(m_min_size.x, v));
    }
    
    void        AMinSize²::min_size(add_k, const Vector2D&v) 
    {
        min_size(SET, Size2D( m_min_size.x+v.x, m_min_size.y+v.y ));
    }
    
    void        AMinSize²::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size2D( m_min_size.x+v, m_min_size.y ));
    }
    
    void        AMinSize²::min_size(add_k, y_k, double v) 
    {
        min_size(SET, Size2D( m_min_size.x, m_min_size.y+v ));
    }

    void        AMinSize²::min_size(multiply_k, double v) 
    {
        min_size(SET, Size2D( m_min_size.x*v, m_min_size.y*v ));
    }
    
    void        AMinSize²::min_size(multiply_k, const Vector2D& v) 
    {
        min_size(SET, Size2D( m_min_size.x*v.x, m_min_size.y*v.y ));
    }
    
    void        AMinSize²::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size2D( m_min_size.x*v, m_min_size.y ));
    }
    
    void        AMinSize²::min_size(multiply_k, y_k, double v) 
    {
        min_size(SET, Size2D( m_min_size.x, m_min_size.y*v ));
    }
    
    void        AMinSize²::on_set_min_size2(const SetMinSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize²::on_set_min_sizeX(const SetMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize²::on_set_min_sizeY(const SetMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize²::on_add_min_size2(const AddMinSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize²::on_add_min_sizeX(const AddMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize²::on_add_min_sizeY(const AddMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize²::on_multiply_min_size(const MultiplyMinSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize²::on_multiply_min_size2(const MultiplyMinSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize²::on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMinSize²::on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
}
