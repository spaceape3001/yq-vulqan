////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/ASize1.hpp>
#include <tachyon/command/size/AddSize1.hpp>
#include <tachyon/command/size/AddSizeX.hpp>
#include <tachyon/command/size/MultiplySize.hpp>
#include <tachyon/command/size/MultiplySize1.hpp>
#include <tachyon/command/size/MultiplySizeX.hpp>
#include <tachyon/command/size/SetSize1.hpp>
#include <tachyon/command/size/SetSizeX.hpp>
#include <tachyon/event/spatial/Size1Event.hpp>


namespace yq::tachyon {
    ASize¹::ASize¹()
    {
    }
    
    ASize¹::~ASize¹()
    {
    }

    void        ASize¹::size(emit_k)
    {
        send(new Size¹Event({.source=typed()}, m_size));
    }
    
    void        ASize¹::size(set_k, const Size1D& sz) 
    {
        m_size  =    sz;
        mark();
        size(EMIT);
    }
    
    void        ASize¹::size(set_k, x_k, double v) 
    {
        size(SET, Size1D(v));
    }
    
    void        ASize¹::size(add_k, const Vector1D&v) 
    {
        size(SET, Size1D( m_size.x+v.x ));
    }
    
    void        ASize¹::size(add_k, x_k, double v) 
    {
        size(SET, Size1D( m_size.x+v ));
    }

    void        ASize¹::size(multiply_k, double v) 
    {
        size(SET, Size1D( m_size.x*v ));
    }
    
    void        ASize¹::size(multiply_k, const Vector1D& v) 
    {
        size(SET, Size1D( m_size.x*v.x ));
    }
    
    void        ASize¹::size(multiply_k, x_k, double v) 
    {
        size(SET, Size1D( m_size.x*v));
    }
    
    void        ASize¹::on_set_size1(const SetSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize¹::on_set_sizeX(const SetSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize¹::on_add_size1(const AddSize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize¹::on_add_sizeX(const AddSizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, X, cmd.Δx());
    }
    
    void        ASize¹::on_multiply_size(const MultiplySize&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize¹::on_multiply_size1(const MultiplySize¹&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize¹::on_multiply_sizeX(const MultiplySizeˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
}
