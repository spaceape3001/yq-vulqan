////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AScale2D.hpp"
#include <yq/tachyon/command/scale/AddScale2DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale2DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale2DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/event/spatial/Scale2DEvent.hpp>

namespace yq::tachyon {
    AScale²D::AScale²D()
    {
    }
    
    AScale²D::~AScale²D()
    {
    }

    void        AScale²D::scale(emit_k)
    {
        send(new Scale²DEvent({.source=typed()}, m_scale));
    }

    void        AScale²D::scale(set_k, const Vector2D& sz) 
    {
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale²D::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector2D(v, m_scale.y));
    }
    
    void        AScale²D::scale(set_k, y_k, double v) 
    {
        scale(SET, Vector2D(m_scale.x, v));
    }
    
    void        AScale²D::scale(add_k, const Vector2D&v) 
    {
        scale(SET, Vector2D( m_scale.x+v.x, m_scale.y+v.y ));
    }
    
    void        AScale²D::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x+v, m_scale.y ));
    }
    
    void        AScale²D::scale(add_k, y_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x, m_scale.y+v ));
    }

    void        AScale²D::scale(multiply_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x*v, m_scale.y*v ));
    }
    
    void        AScale²D::scale(multiply_k, const Vector2D& v) 
    {
        scale(SET, Vector2D( m_scale.x*v.x, m_scale.y*v.y ));
    }
    
    void        AScale²D::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x*v, m_scale.y ));
    }
    
    void        AScale²D::scale(multiply_k, y_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x, m_scale.y*v ));
    }
    
    void        AScale²D::on_set_scale2(const SetScale²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale²D::on_set_scaleX(const SetScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale²D::on_set_scaleY(const SetScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale²D::on_add_scale2(const AddScale²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale²D::on_add_scaleX(const AddScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale²D::on_add_scaleY(const AddScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale²D::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale²D::on_multiply_scale2(const MultiplyScale²DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale²D::on_multiply_scaleX(const MultiplyScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale²D::on_multiply_scaleY(const MultiplyScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
}
