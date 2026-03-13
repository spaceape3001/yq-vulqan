////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMinSize1D.hpp"
#include <yq/tachyon/command/size/AddMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/event/spatial/MinSize1DEvent.hpp>


namespace yq::tachyon {
    AMinSize¹D::AMinSize¹D()
    {
    }
    
    AMinSize¹D::~AMinSize¹D()
    {
    }

    void        AMinSize¹D::min_size(emit_k)
    {
        send(new MinSize¹DEvent({.source=typed()}, m_min_size));
    }
    
    void        AMinSize¹D::min_size(set_k, const Size1D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize¹D::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size1D(v));
    }
    
    void        AMinSize¹D::min_size(add_k, const Size1D&v) 
    {
        min_size(SET, Size1D( m_min_size.x+v.x ));
    }
    
    void        AMinSize¹D::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x+v ));
    }

    void        AMinSize¹D::min_size(multiply_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x*v ));
    }
    
    void        AMinSize¹D::min_size(multiply_k, const Vector1D& v) 
    {
        min_size(SET, Size1D( m_min_size.x*v.x ));
    }
    
    void        AMinSize¹D::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x*v));
    }
    
    void        AMinSize¹D::on_set_min_size1(const SetMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize¹D::on_set_min_sizeX(const SetMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize¹D::on_add_min_size1(const AddMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize¹D::on_add_min_sizeX(const AddMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize¹D::on_multiply_min_size(const MultiplyMinSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹D::on_multiply_min_size1(const MultiplyMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹D::on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
}
