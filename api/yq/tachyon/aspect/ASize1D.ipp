////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ASize1D.hpp"
#include <yq/tachyon/command/size/AddSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplySize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplySizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetSizeXDCommand.hpp>
#include <yq/tachyon/event/spatial/Size1DEvent.hpp>


namespace yq::tachyon {
    ASize¹D::ASize¹D()
    {
    }
    
    ASize¹D::~ASize¹D()
    {
    }

    void        ASize¹D::size(emit_k)
    {
        send(new Size¹DEvent({.source=typed()}, m_size));
    }
    
    void        ASize¹D::size(set_k, const Size1D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize¹D::size(set_k, x_k, double v) 
    {
        size(SET, Size1D(v));
    }
    
    void        ASize¹D::size(add_k, const Size1D&v) 
    {
        size(SET, Size1D( m_size.x+v.x ));
    }
    
    void        ASize¹D::size(add_k, x_k, double v) 
    {
        size(SET, Size1D( m_size.x+v ));
    }

    void        ASize¹D::size(multiply_k, double v) 
    {
        size(SET, Size1D( m_size.x*v ));
    }
    
    void        ASize¹D::size(multiply_k, const Vector1D& v) 
    {
        size(SET, Size1D( m_size.x*v.x ));
    }
    
    void        ASize¹D::size(multiply_k, x_k, double v) 
    {
        size(SET, Size1D( m_size.x*v));
    }
    
    void        ASize¹D::on_set_size1(const SetSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize¹D::on_set_sizeX(const SetSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize¹D::on_add_size1(const AddSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize¹D::on_add_sizeX(const AddSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize¹D::on_multiply_size(const MultiplySizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize¹D::on_multiply_size1(const MultiplySize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize¹D::on_multiply_sizeX(const MultiplySizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
}
