////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaxSize2D.hpp"
#include <yq/tachyon/command/size/AddMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>
#include <yq/tachyon/event/spatial/MaxSize2DEvent.hpp>


namespace yq::tachyon {
    AMaxSize²D::AMaxSize²D()
    {
    }
    
    AMaxSize²D::~AMaxSize²D()
    {
    }

    void        AMaxSize²D::max_size(emit_k)
    {
        send(new MaxSize²DEvent({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize²D::max_size(set_k, const Size2D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize²D::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size2D(v, m_max_size.y));
    }
    
    void        AMaxSize²D::max_size(set_k, y_k, double v) 
    {
        max_size(SET, Size2D(m_max_size.x, v));
    }
    
    void        AMaxSize²D::max_size(add_k, const Size2D&v) 
    {
        max_size(SET, Size2D( m_max_size.x+v.x, m_max_size.y+v.y ));
    }
    
    void        AMaxSize²D::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x+v, m_max_size.y ));
    }
    
    void        AMaxSize²D::max_size(add_k, y_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x, m_max_size.y+v ));
    }

    void        AMaxSize²D::max_size(multiply_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x*v, m_max_size.y*v ));
    }
    
    void        AMaxSize²D::max_size(multiply_k, const Vector2D& v) 
    {
        max_size(SET, Size2D( m_max_size.x*v.x, m_max_size.y*v.y ));
    }
    
    void        AMaxSize²D::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x*v, m_max_size.y ));
    }
    
    void        AMaxSize²D::max_size(multiply_k, y_k, double v) 
    {
        max_size(SET, Size2D( m_max_size.x, m_max_size.y*v ));
    }
    
    void        AMaxSize²D::on_set_max_size2(const SetMaxSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize²D::on_set_max_sizeX(const SetMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize²D::on_set_max_sizeY(const SetMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, Y, cmd.y());
    }
    
    void        AMaxSize²D::on_add_max_size2(const AddMaxSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize²D::on_add_max_sizeX(const AddMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize²D::on_add_max_sizeY(const AddMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δy());
    }
    
    void        AMaxSize²D::on_multiply_max_size(const MultiplyMaxSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize²D::on_multiply_max_size2(const MultiplyMaxSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize²D::on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
    
    void        AMaxSize²D::on_multiply_max_sizeY(const MultiplyMaxSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, Y, cmd.δy());
    }
}
