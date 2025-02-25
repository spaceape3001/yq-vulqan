////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AMaxSize1.hpp>
#include <ya/commands/size/AddMaxSize1.hpp>
#include <ya/commands/size/AddMaxSizeX.hpp>
#include <ya/commands/size/MultiplyMaxSize.hpp>
#include <ya/commands/size/MultiplyMaxSize1.hpp>
#include <ya/commands/size/MultiplyMaxSizeX.hpp>
#include <ya/commands/size/SetMaxSize1.hpp>
#include <ya/commands/size/SetMaxSizeX.hpp>
#include <ya/events/spatial/Size1Event.hpp>


namespace yq::tachyon {
    AMaxSize¹::AMaxSize¹()
    {
    }
    
    AMaxSize¹::~AMaxSize¹()
    {
    }

    void        AMaxSize¹::max_size(emit_k)
    {
        send(new Size¹Event({.source=typed()}, m_max_size));
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
    
    void        AMaxSize¹::on_set_max_size1(const SetMaxSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize¹::on_set_max_sizeX(const SetMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize¹::on_add_max_size1(const AddMaxSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize¹::on_add_max_sizeX(const AddMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, X, cmd.Δx());
    }
    
    void        AMaxSize¹::on_multiply_max_size(const MultiplyMaxSize&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹::on_multiply_max_size1(const MultiplyMaxSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹::on_multiply_max_sizeX(const MultiplyMaxSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
}
