////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMaxSize1.hpp"
#include <yq/tachyon/command/size/AddMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/event/spatial/MaxSize1DEvent.hpp>


namespace yq::tachyon {
    AMaxSize¹::AMaxSize¹()
    {
    }
    
    AMaxSize¹::~AMaxSize¹()
    {
    }

    void        AMaxSize¹::max_size(emit_k)
    {
        send(new MaxSize¹DEvent({.source=typed()}, m_max_size));
    }
    
    void        AMaxSize¹::max_size(set_k, const Size1D& sz) 
    {
        m_max_size  =    sz;
        mark();
        max_size(EMIT);
    }
    
    void        AMaxSize¹::max_size(set_k, x_k, double v) 
    {
        max_size(SET, Size1D(v));
    }
    
    void        AMaxSize¹::max_size(add_k, const Vector1D&v) 
    {
        max_size(SET, Size1D( m_max_size.x+v.x ));
    }
    
    void        AMaxSize¹::max_size(add_k, x_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x+v ));
    }

    void        AMaxSize¹::max_size(multiply_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x*v ));
    }
    
    void        AMaxSize¹::max_size(multiply_k, const Vector1D& v) 
    {
        max_size(SET, Size1D( m_max_size.x*v.x ));
    }
    
    void        AMaxSize¹::max_size(multiply_k, x_k, double v) 
    {
        max_size(SET, Size1D( m_max_size.x*v));
    }
    
    void        AMaxSize¹::on_set_max_size1(const SetMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize¹::on_set_max_sizeX(const SetMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize¹::on_add_max_size1(const AddMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize¹::on_add_max_sizeX(const AddMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize¹::on_multiply_max_size(const MultiplyMaxSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹::on_multiply_max_size1(const MultiplyMaxSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹::on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
}
