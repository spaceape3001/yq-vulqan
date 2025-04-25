////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMaxSize2.hpp>
#include <tachyon/command/size/AddMaxSize2.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize2.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSize2.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/event/spatial/Size2Event.hpp>


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
    
    void        AMaxSize²::on_set_max_size2(const SetMaxSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize²::on_set_max_sizeX(const SetMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize²::on_set_max_sizeY(const SetMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize²::on_add_max_size2(const AddMaxSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize²::on_add_max_sizeX(const AddMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize²::on_add_max_sizeY(const AddMaxSizeʸ&cmd)
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
    
    void        AMaxSize²::on_multiply_max_size2(const MultiplyMaxSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize²::on_multiply_max_sizeX(const MultiplyMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize²::on_multiply_max_sizeY(const MultiplyMaxSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
}
