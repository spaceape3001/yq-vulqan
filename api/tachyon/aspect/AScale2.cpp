////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/aspect/AScale2.hpp>
#include <tachyon/command/scale/AddScale2.hpp>
#include <tachyon/command/scale/AddScaleX.hpp>
#include <tachyon/command/scale/AddScaleY.hpp>
#include <tachyon/command/scale/MultiplyScale.hpp>
#include <tachyon/command/scale/MultiplyScale2.hpp>
#include <tachyon/command/scale/MultiplyScaleX.hpp>
#include <tachyon/command/scale/MultiplyScaleY.hpp>
#include <tachyon/command/scale/SetScale2.hpp>
#include <tachyon/command/scale/SetScaleX.hpp>
#include <tachyon/command/scale/SetScaleY.hpp>
#include <tachyon/event/spatial/Scale2Event.hpp>

namespace yq::tachyon {
    AScale²::AScale²()
    {
    }
    
    AScale²::~AScale²()
    {
    }

    void        AScale²::scale(emit_k)
    {
        send(new Scale²Event({.source=typed()}, m_scale));
    }

    void        AScale²::scale(set_k, const Vector2D& sz) 
    {
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale²::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector2D(v, m_scale.y));
    }
    
    void        AScale²::scale(set_k, y_k, double v) 
    {
        scale(SET, Vector2D(m_scale.x, v));
    }
    
    void        AScale²::scale(add_k, const Vector2D&v) 
    {
        scale(SET, Vector2D( m_scale.x+v.x, m_scale.y+v.y ));
    }
    
    void        AScale²::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x+v, m_scale.y ));
    }
    
    void        AScale²::scale(add_k, y_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x, m_scale.y+v ));
    }

    void        AScale²::scale(multiply_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x*v, m_scale.y*v ));
    }
    
    void        AScale²::scale(multiply_k, const Vector2D& v) 
    {
        scale(SET, Vector2D( m_scale.x*v.x, m_scale.y*v.y ));
    }
    
    void        AScale²::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x*v, m_scale.y ));
    }
    
    void        AScale²::scale(multiply_k, y_k, double v) 
    {
        scale(SET, Vector2D( m_scale.x, m_scale.y*v ));
    }
    
    void        AScale²::on_set_scale2(const SetScale²&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale²::on_set_scaleX(const SetScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale²::on_set_scaleY(const SetScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale²::on_add_scale2(const AddScale²&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale²::on_add_scaleX(const AddScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale²::on_add_scaleY(const AddScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale²::on_multiply_scale(const MultiplyScale&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale²::on_multiply_scale2(const MultiplyScale²&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale²::on_multiply_scaleX(const MultiplyScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale²::on_multiply_scaleY(const MultiplyScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
}
