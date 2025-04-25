////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/ASize2.hpp>
#include <tachyon/command/size/AddSize2.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/AddSizeY.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize2.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/MultiplySizeY.hpp>
#include <tachyon/command/size/SetSize2.hpp>
#include <tachyon/command/size/SetSizeX.hpp>
#include <tachyon/command/size/SetSizeY.hpp>
#include <tachyon/event/spatial/Size2Event.hpp>


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
    
    void        ASize²::on_set_size2(const SetSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize²::on_set_sizeX(const SetSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize²::on_set_sizeY(const SetSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize²::on_add_size2(const AddSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize²::on_add_sizeX(const AddSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize²::on_add_sizeY(const AddSizeʸ&cmd)
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
    
    void        ASize²::on_multiply_size2(const MultiplySize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize²::on_multiply_sizeX(const MultiplySizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize²::on_multiply_sizeY(const MultiplySizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
}
