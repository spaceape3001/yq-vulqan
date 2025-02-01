////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMinSize1.hpp>
#include <ya/commands/spatial/AddMinSize1.hpp>
#include <ya/commands/spatial/AddMinSizeX.hpp>
#include <ya/commands/spatial/MultiplyMinSize.hpp>
#include <ya/commands/spatial/MultiplyMinSize1.hpp>
#include <ya/commands/spatial/MultiplyMinSizeX.hpp>
#include <ya/commands/spatial/SetMinSize1.hpp>
#include <ya/commands/spatial/SetMinSizeX.hpp>
#include <ya/events/spatial/Size1Event.hpp>


namespace yq::tachyon {
    AMinSize¹::AMinSize¹()
    {
    }
    
    AMinSize¹::~AMinSize¹()
    {
    }

    void        AMinSize¹::min_size(emit_k)
    {
        send(new Size¹Event({.source=typed()}, m_min_size));
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
    
    void        AMinSize¹::on_set_min_size1(const SetMinSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, cmd.size());
    }
    
    void        AMinSize¹::on_set_min_sizeX(const SetMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(SET, X, cmd.x());
    }
    
    void        AMinSize¹::on_add_min_size1(const AddMinSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, cmd.Δ());
    }
    
    void        AMinSize¹::on_add_min_sizeX(const AddMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(ADD, X, cmd.Δx());
    }
    
    void        AMinSize¹::on_multiply_min_size(const MultiplyMinSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹::on_multiply_min_size1(const MultiplyMinSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, cmd.δ());
    }
    
    void        AMinSize¹::on_multiply_min_sizeX(const MultiplyMinSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        min_size(MULTIPLY, X, cmd.δx());
    }
}
