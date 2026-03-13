////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASize2D.hpp"
#include <yq/tachyon/command/size/AddSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSizeYDCommand.hpp>
#include <yq/tachyon/event/spatial/Size2DEvent.hpp>


namespace yq::tachyon {
    ASize²D::ASize²D()
    {
    }
    
    ASize²D::~ASize²D()
    {
    }

    void        ASize²D::size(emit_k)
    {
        send(new Size²DEvent({.source=typed()}, m_size));
    }
    
    void        ASize²D::size(set_k, const Size2D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize²D::size(set_k, x_k, double v) 
    {
        size(SET, Size2D(v, m_size.y));
    }
    
    void        ASize²D::size(set_k, y_k, double v) 
    {
        size(SET, Size2D(m_size.x, v));
    }
    
    void        ASize²D::size(add_k, const Size2D&v) 
    {
        size(SET, Size2D( m_size.x+v.x, m_size.y+v.y ));
    }
    
    void        ASize²D::size(add_k, x_k, double v) 
    {
        size(SET, Size2D( m_size.x+v, m_size.y ));
    }
    
    void        ASize²D::size(add_k, y_k, double v) 
    {
        size(SET, Size2D( m_size.x, m_size.y+v ));
    }

    void        ASize²D::size(multiply_k, double v) 
    {
        size(SET, Size2D( m_size.x*v, m_size.y*v ));
    }
    
    void        ASize²D::size(multiply_k, const Vector2D& v) 
    {
        size(SET, Size2D( m_size.x*v.x, m_size.y*v.y ));
    }
    
    void        ASize²D::size(multiply_k, x_k, double v) 
    {
        size(SET, Size2D( m_size.x*v, m_size.y ));
    }
    
    void        ASize²D::size(multiply_k, y_k, double v) 
    {
        size(SET, Size2D( m_size.x, m_size.y*v ));
    }
    
    void        ASize²D::on_set_size2(const SetSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize²D::on_set_sizeX(const SetSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize²D::on_set_sizeY(const SetSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, Y, cmd.y());
    }
    
    void        ASize²D::on_add_size2(const AddSize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize²D::on_add_sizeX(const AddSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize²D::on_add_sizeY(const AddSizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δy());
    }
    
    void        ASize²D::on_multiply_size(const MultiplySizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize²D::on_multiply_size2(const MultiplySize²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize²D::on_multiply_sizeX(const MultiplySizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
    
    void        ASize²D::on_multiply_sizeY(const MultiplySizeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, Y, cmd.δy());
    }
}
