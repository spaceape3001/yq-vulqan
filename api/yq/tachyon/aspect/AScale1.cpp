////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AScale1.hpp>
#include <yq/tachyon/command/scale/AddScale1DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale1DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale1DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/event/spatial/Scale1DEvent.hpp>


namespace yq::tachyon {
    AScale¹::AScale¹()
    {
    }
    
    AScale¹::~AScale¹()
    {
    }

    void        AScale¹::scale(emit_k)
    {
        send(new Scale¹DEvent({.source=typed()}, m_scale));
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
    
    void        AScale¹::on_set_scale1(const SetScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale¹::on_set_scaleX(const SetScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale¹::on_add_scale1(const AddScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale¹::on_add_scaleX(const AddScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale¹::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹::on_multiply_scale1(const MultiplyScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹::on_multiply_scaleX(const MultiplyScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
}
