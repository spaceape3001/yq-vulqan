////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/ASize2.hpp>
#include <yq/tachyon/command/size/AddSize2Command.hpp>
#include <yq/tachyon/command/size/AddSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize2Command.hpp>
#include <yq/tachyon/command/size/MultiplySizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYCommand.hpp>
#include <yq/tachyon/command/size/SetSize2Command.hpp>
#include <yq/tachyon/command/size/SetSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYCommand.hpp>
#include <yq/tachyon/event/spatial/Size2Event.hpp>


namespace yq::tachyon {
    ASize²::ASize²()
    {
    }
    
    ASize²::~ASize²()
    {
    }

    void        ASize²::size(emit_k)
    {
        send(new Size²Event({.source=typed()}, m_size));
    }
    
    void        ASize²::size(set_k, const Size2D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize²::size(set_k, x_k, double v) 
    {
        size(SET, Size2D(v, m_size.y));
    }
    
    void        ASize²::size(set_k, y_k, double v) 
    {
        size(SET, Size2D(m_size.x, v));
    }
    
    void        ASize²::size(add_k, const Vector2D&v) 
    {
        size(SET, Size2D( m_size.x+v.x, m_size.y+v.y ));
    }
    
    void        ASize²::size(add_k, x_k, double v) 
    {
        size(SET, Size2D( m_size.x+v, m_size.y ));
    }
    
    void        ASize²::size(add_k, y_k, double v) 
    {
        size(SET, Size2D( m_size.x, m_size.y+v ));
    }

    void        ASize²::size(multiply_k, double v) 
    {
        size(SET, Size2D( m_size.x*v, m_size.y*v ));
    }
    
    void        ASize²::size(multiply_k, const Vector2D& v) 
    {
        size(SET, Size2D( m_size.x*v.x, m_size.y*v.y ));
    }
    
    void        ASize²::size(multiply_k, x_k, double v) 
    {
        size(SET, Size2D( m_size.x*v, m_size.y ));
    }
    
    void        ASize²::size(multiply_k, y_k, double v) 
    {
        size(SET, Size2D( m_size.x, m_size.y*v ));
    }
    
    void        ASize²::on_set_size2(const SetSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize²::on_set_sizeX(const SetSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize²::on_set_sizeY(const SetSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize²::on_add_size2(const AddSize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize²::on_add_sizeX(const AddSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize²::on_add_sizeY(const AddSizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize²::on_multiply_size(const MultiplySize&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize²::on_multiply_size2(const MultiplySize²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize²::on_multiply_sizeX(const MultiplySizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize²::on_multiply_sizeY(const MultiplySizeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
}
