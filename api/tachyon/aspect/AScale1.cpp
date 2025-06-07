////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/AScale1.hpp>
#include <tachyon/command/scale/AddScale1Command.hpp>
#include <tachyon/command/scale/AddScaleXCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <tachyon/command/scale/MultiplyScale1Command.hpp>
#include <tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <tachyon/command/scale/SetScale1Command.hpp>
#include <tachyon/command/scale/SetScaleXCommand.hpp>
#include <tachyon/event/spatial/Scale1Event.hpp>


namespace yq::tachyon {
    AScale¹::AScale¹()
    {
    }
    
    AScale¹::~AScale¹()
    {
    }

    void        AScale¹::scale(emit_k)
    {
        send(new Scale¹Event({.source=typed()}, m_scale));
    }

    void        AScale¹::scale(set_k, const Vector1D& sz) 
    {
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale¹::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector1D(v));
    }
    
    void        AScale¹::scale(add_k, const Vector1D&v) 
    {
        scale(SET, Vector1D( m_scale.x+v.x ));
    }
    
    void        AScale¹::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x+v ));
    }

    void        AScale¹::scale(multiply_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x*v ));
    }
    
    void        AScale¹::scale(multiply_k, const Vector1D& v) 
    {
        scale(SET, Vector1D( m_scale.x*v.x ));
    }
    
    void        AScale¹::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x*v));
    }
    
    void        AScale¹::on_set_scale1(const SetScale¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale¹::on_set_scaleX(const SetScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale¹::on_add_scale1(const AddScale¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale¹::on_add_scaleX(const AddScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale¹::on_multiply_scale(const MultiplyScaleCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹::on_multiply_scale1(const MultiplyScale¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹::on_multiply_scaleX(const MultiplyScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
}
