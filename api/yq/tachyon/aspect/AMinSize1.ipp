////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMinSize1.hpp"
#include <yq/tachyon/command/size/AddMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/event/spatial/MinSize1DEvent.hpp>


namespace yq::tachyon {
    AMinSize¹::AMinSize¹()
    {
    }
    
    AMinSize¹::~AMinSize¹()
    {
    }

    void        AMinSize¹::min_size(emit_k)
    {
        send(new MinSize¹DEvent({.source=typed()}, m_min_size));
    }
    
    void        AMinSize¹::min_size(set_k, const Size1D& sz) 
    {
        m_min_size  =    sz;
        mark();
        min_size(EMIT);
    }
    
    void        AMinSize¹::min_size(set_k, x_k, double v) 
    {
        min_size(SET, Size1D(v));
    }
    
    void        AMinSize¹::min_size(add_k, const Vector1D&v) 
    {
        min_size(SET, Size1D( m_min_size.x+v.x ));
    }
    
    void        AMinSize¹::min_size(add_k, x_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x+v ));
    }

    void        AMinSize¹::min_size(multiply_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x*v ));
    }
    
    void        AMinSize¹::min_size(multiply_k, const Vector1D& v) 
    {
        min_size(SET, Size1D( m_min_size.x*v.x ));
    }
    
    void        AMinSize¹::min_size(multiply_k, x_k, double v) 
    {
        min_size(SET, Size1D( m_min_size.x*v));
    }
    
    void        AMinSize¹::on_set_min_size1(const SetMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize¹::on_set_min_sizeX(const SetMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize¹::on_add_min_size1(const AddMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize¹::on_add_min_sizeX(const AddMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize¹::on_multiply_min_size(const MultiplyMinSizeDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹::on_multiply_min_size1(const MultiplyMinSize¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹::on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
}
