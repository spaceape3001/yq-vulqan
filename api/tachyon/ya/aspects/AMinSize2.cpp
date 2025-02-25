////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMinSize2.hpp>
#include <ya/commands/size/AddMinSize2.hpp>
#include <ya/commands/size/AddMinSizeX.hpp>
#include <ya/commands/size/AddMinSizeY.hpp>
#include <ya/commands/size/MultiplyMinSize.hpp>
#include <ya/commands/size/MultiplyMinSize2.hpp>
#include <ya/commands/size/MultiplyMinSizeX.hpp>
#include <ya/commands/size/MultiplyMinSizeY.hpp>
#include <ya/commands/size/SetMinSize2.hpp>
#include <ya/commands/size/SetMinSizeX.hpp>
#include <ya/commands/size/SetMinSizeY.hpp>
#include <ya/events/spatial/Size2Event.hpp>


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
    
    void        AMinSize²::on_set_min_size2(const SetMinSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize²::on_set_min_sizeX(const SetMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize²::on_set_min_sizeY(const SetMinSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize²::on_add_min_size2(const AddMinSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize²::on_add_min_sizeX(const AddMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize²::on_add_min_sizeY(const AddMinSizeʸ&cmd)
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
    
    void        AMinSize²::on_multiply_min_size2(const MultiplyMinSize²&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize²::on_multiply_min_sizeX(const MultiplyMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMinSize²::on_multiply_min_sizeY(const MultiplyMinSizeʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
}
