////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMinSize2.hpp"
#include <yq/tachyon/command/size/AddMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/event/spatial/MinSize2DEvent.hpp>


namespace yq::tachyon {
    AMinSize²::AMinSize²()
    {
    }
    
    AMinSize²::~AMinSize²()
    {
    }

    void        AMinSize²::min_size(emit_k)
    {
        send(new MinSize²DEvent({.source=typed()}, m_min_size));
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
    
    void        AMinSize²::on_set_min_size2(const SetMinSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize²::on_set_min_sizeX(const SetMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize²::on_set_min_sizeY(const SetMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, Y, cmd.y());
    }
    
    void        AMinSize²::on_add_min_size2(const AddMinSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize²::on_add_min_sizeX(const AddMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize²::on_add_min_sizeY(const AddMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δy());
    }
    
    void        AMinSize²::on_multiply_min_size(const MultiplyMinSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize²::on_multiply_min_size2(const MultiplyMinSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize²::on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMinSize²::on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, Y, cmd.δy());
    }
}
