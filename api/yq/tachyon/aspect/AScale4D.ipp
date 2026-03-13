////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AScale4D.hpp"
#include <yq/tachyon/command/scale/AddScale4DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale4DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale4DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>
#include <yq/tachyon/event/spatial/Scale4DEvent.hpp>


namespace yq::tachyon {
    AScale⁴D::AScale⁴D(const Vector4D& sca)
    {
        if(!is_nan(sca))
            m_scale = sca;
    }
    
    AScale⁴D::AScale⁴D(const Param& p) : AScale⁴D(p.scale)
    {
    }

    AScale⁴D::~AScale⁴D()
    {
    }

    void        AScale⁴D::scale(emit_k)
    {
        send(new Scale⁴DEvent({.source=typed()}, m_scale));
    }

    void        AScale⁴D::scale(set_k, const Vector4D& sz) 
    {
        if(is_nan(sz))
            return ;
            
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale⁴D::scale(set_k, w_k, double v) 
    {
        scale(SET, Vector4D(m_scale.x, m_scale.y, m_scale.z, v));
    }

    void        AScale⁴D::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector4D(v, m_scale.y, m_scale.z, m_scale.w));
    }
    
    void        AScale⁴D::scale(set_k, y_k, double v) 
    {
        scale(SET, Vector4D(m_scale.x,v, m_scale.z, m_scale.w));
    }
    
    void        AScale⁴D::scale(set_k, z_k, double v) 
    {
        scale(SET, Vector4D(m_scale.x, m_scale.y, v, m_scale.w));
    }
    
    void        AScale⁴D::scale(add_k, const Vector4D&v) 
    {
        scale(SET, Vector4D( m_scale.x+v.x, m_scale.y+v.y, m_scale.z+v.z, m_scale.w+v.w ));
    }
    
    void        AScale⁴D::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x+v, m_scale.y, m_scale.z, m_scale.w ));
    }
    
    void        AScale⁴D::scale(add_k, y_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y+v, m_scale.z, m_scale.w ));
    }
    
    void        AScale⁴D::scale(add_k, z_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y, m_scale.z+v, m_scale.w ));
    }

    void        AScale⁴D::scale(add_k, w_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y, m_scale.z, m_scale.w+v ));
    }

    void        AScale⁴D::scale(multiply_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x*v, m_scale.y*v, m_scale.z*v, m_scale.w*v ));
    }
    
    void        AScale⁴D::scale(multiply_k, const Vector4D& v) 
    {
        scale(SET, Vector4D( m_scale.x*v.x, m_scale.y*v.y, m_scale.z*v.z, m_scale.w*v.w ));
    }
    
    void        AScale⁴D::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x*v, m_scale.y, m_scale.z, m_scale.w ));
    }
    
    void        AScale⁴D::scale(multiply_k, y_k, double v) 
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y*v, m_scale.z, m_scale.w ));
    }
    
    void        AScale⁴D::scale(multiply_k, z_k, double v)
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y, m_scale.z*v, m_scale.w ));
    }
    
    void        AScale⁴D::scale(multiply_k, w_k, double v)
    {
        scale(SET, Vector4D( m_scale.x, m_scale.y, m_scale.z, m_scale.w*v ));
    }
    
    void        AScale⁴D::on_set_scale4(const SetScale⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale⁴D::on_set_scaleW(const SetScaleʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, W, cmd.w());
    }
    
    void        AScale⁴D::on_set_scaleX(const SetScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }

    void        AScale⁴D::on_set_scaleY(const SetScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale⁴D::on_set_scaleZ(const SetScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Z, cmd.z());
    }

    void        AScale⁴D::on_add_scale4(const AddScale⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale⁴D::on_add_scaleW(const AddScaleʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, W, cmd.Δw());
    }

    void        AScale⁴D::on_add_scaleX(const AddScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale⁴D::on_add_scaleY(const AddScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale⁴D::on_add_scaleZ(const AddScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δz());
    }
    
    void        AScale⁴D::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale⁴D::on_multiply_scale4(const MultiplyScale⁴DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale⁴D::on_multiply_scaleW(const MultiplyScaleʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, W, cmd.δw());
    }

    void        AScale⁴D::on_multiply_scaleX(const MultiplyScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale⁴D::on_multiply_scaleY(const MultiplyScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
    
    void        AScale⁴D::on_multiply_scaleZ(const MultiplyScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Z, cmd.δz());
    }
}
