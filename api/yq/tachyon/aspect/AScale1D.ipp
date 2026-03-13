////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AScale1D.hpp"

#include <yq/tachyon/command/scale/AddScale1DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale1DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale1DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/event/spatial/Scale1DEvent.hpp>


namespace yq::tachyon {
    AScale¹D::AScale¹D()
    {
    }
    
    AScale¹D::~AScale¹D()
    {
    }

    void        AScale¹D::scale(emit_k)
    {
        send(new Scale¹DEvent({.source=typed()}, m_scale));
    }

    void        AScale¹D::scale(set_k, const Vector1D& sz) 
    {
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale¹D::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector1D(v));
    }
    
    void        AScale¹D::scale(add_k, const Vector1D&v) 
    {
        scale(SET, Vector1D( m_scale.x+v.x ));
    }
    
    void        AScale¹D::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x+v ));
    }

    void        AScale¹D::scale(multiply_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x*v ));
    }
    
    void        AScale¹D::scale(multiply_k, const Vector1D& v) 
    {
        scale(SET, Vector1D( m_scale.x*v.x ));
    }
    
    void        AScale¹D::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector1D( m_scale.x*v));
    }
    
    void        AScale¹D::on_set_scale1(const SetScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale¹D::on_set_scaleX(const SetScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale¹D::on_add_scale1(const AddScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale¹D::on_add_scaleX(const AddScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale¹D::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹D::on_multiply_scale1(const MultiplyScale¹DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale¹D::on_multiply_scaleX(const MultiplyScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
}
