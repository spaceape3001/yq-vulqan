////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/AMaxSize1.hpp>
#include <tachyon/command/size/AddMaxSize1Command.hpp>
#include <tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSize1Command.hpp>
#include <tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <tachyon/command/size/SetMaxSize1Command.hpp>
#include <tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <tachyon/event/spatial/Size1Event.hpp>


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
    
    void        AMaxSize¹::on_set_max_size1(const SetMaxSize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, cmd.size());
    }
    
    void        AMaxSize¹::on_set_max_sizeX(const SetMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(SET, X, cmd.x());
    }
    
    void        AMaxSize¹::on_add_max_size1(const AddMaxSize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(ADD, cmd.Δ());
    }
    
    void        AMaxSize¹::on_add_max_sizeX(const AddMaxSizeˣCommand&cmd)
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
    
    void        AMaxSize¹::on_multiply_max_size1(const MultiplyMaxSize¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, cmd.δ());
    }
    
    void        AMaxSize¹::on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        max_size(MULTIPLY, X, cmd.δx());
    }
}
