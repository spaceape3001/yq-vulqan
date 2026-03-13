////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaxSize1D.hpp"
#include <yq/tachyon/command/size/AddMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/event/spatial/MaxSize1DEvent.hpp>


namespace yq::tachyon {
    AMaxSize¹D::AMaxSize¹D()
    {
    }
    
    AMaxSize¹D::~AMaxSize¹D()
    {
    }

    void        AMaxSize¹D::max_size(emit_k)
    {
        send(new MaxSize¹DEvent({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize¹D::max_size(set_k, const Size1D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize¹D::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size1D(v));
    }
    
    void        AMaxSize¹D::max_size(add_k, const Size1D&v) 
    {
        max_size(SET, Size1D( m_max_size.x+v.x ));
    }
    
    void        AMaxSize¹D::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x+v ));
    }

    void        AMaxSize¹D::max_size(multiply_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x*v ));
    }
    
    void        AMaxSize¹D::max_size(multiply_k, const Vector1D& v) 
    {
        max_size(SET, Size1D( m_max_size.x*v.x ));
    }
    
    void        AMaxSize¹D::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x*v));
    }
    
    void        AMaxSize¹D::on_set_max_size1(const SetMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize¹D::on_set_max_sizeX(const SetMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize¹D::on_add_max_size1(const AddMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize¹D::on_add_max_sizeX(const AddMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize¹D::on_multiply_max_size(const MultiplyMaxSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹D::on_multiply_max_size1(const MultiplyMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹D::on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
}
