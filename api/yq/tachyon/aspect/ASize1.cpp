////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/ASize1.hpp>
#include <tachyon/command/size/AddSize1Command.hpp>
#include <tachyon/command/size/AddSizeXCommand.hpp>
#include <tachyon/command/size/MultiplySizeCommand.hpp>
#include <tachyon/command/size/MultiplySize1Command.hpp>
#include <tachyon/command/size/MultiplySizeXCommand.hpp>
#include <tachyon/command/size/SetSize1Command.hpp>
#include <tachyon/command/size/SetSizeXCommand.hpp>
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
    
    void        ASize¹::on_set_size1(const SetSize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, cmd.size());
    }
    
    void        ASize¹::on_set_sizeX(const SetSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(SET, X, cmd.x());
    }
    
    void        ASize¹::on_add_size1(const AddSize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(ADD, cmd.Δ());
    }
    
    void        ASize¹::on_add_sizeX(const AddSizeˣCommand&cmd)
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
    
    void        ASize¹::on_multiply_size1(const MultiplySize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, cmd.δ());
    }
    
    void        ASize¹::on_multiply_sizeX(const MultiplySizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        size(MULTIPLY, X, cmd.δx());
    }
}
