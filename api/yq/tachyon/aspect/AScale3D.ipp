////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AScale3D.hpp"
#include <yq/tachyon/command/scale/AddScale3DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>
#include <yq/tachyon/event/spatial/Scale3DEvent.hpp>


namespace yq::tachyon {
    AScale³D::AScale³D(const Vector3D& sca)
    {
        if(!is_nan(sca))
            m_scale = sca;
    }
    
    AScale³D::AScale³D(const Param& p) : AScale³D(p.scale)
    {
    }

    AScale³D::~AScale³D()
    {
    }

    void        AScale³D::scale(emit_k)
    {
        send(new Scale³DEvent({.source=typed()}, m_scale));
    }

    void        AScale³D::scale(set_k, const Vector3D& sz) 
    {
        if(is_nan(sz))
            return ;
            
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale³D::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector3D(v, m_scale.y, m_scale.z));
    }
    
    void        AScale³D::scale(set_k, y_k, double v) 
    {
        scale(SET, Vector3D(m_scale.x,v, m_scale.z));
    }
    
    void        AScale³D::scale(set_k, z_k, double v) 
    {
        scale(SET, Vector3D(m_scale.x, m_scale.y, v));
    }
    
    void        AScale³D::scale(add_k, const Vector3D&v) 
    {
        scale(SET, Vector3D( m_scale.x+v.x, m_scale.y+v.y, m_scale.z+v.z ));
    }
    
    void        AScale³D::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x+v, m_scale.y, m_scale.z ));
    }
    
    void        AScale³D::scale(add_k, y_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y+v, m_scale.z ));
    }
    
    void        AScale³D::scale(add_k, z_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y, m_scale.z+v ));
    }

    void        AScale³D::scale(multiply_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x*v, m_scale.y*v, m_scale.z*v ));
    }
    
    void        AScale³D::scale(multiply_k, const Vector3D& v) 
    {
        scale(SET, Vector3D( m_scale.x*v.x, m_scale.y*v.y, m_scale.z*v.z ));
    }
    
    void        AScale³D::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x*v, m_scale.y, m_scale.z ));
    }
    
    void        AScale³D::scale(multiply_k, y_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y*v, m_scale.z ));
    }
    
    void        AScale³D::scale(multiply_k, z_k, double v)
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y, m_scale.z*v ));
    }
    
    void        AScale³D::on_set_scale3(const SetScale³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale³D::on_set_scaleX(const SetScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale³D::on_set_scaleY(const SetScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale³D::on_set_scaleZ(const SetScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Z, cmd.z());
    }

    void        AScale³D::on_add_scale3(const AddScale³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale³D::on_add_scaleX(const AddScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale³D::on_add_scaleY(const AddScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale³D::on_add_scaleZ(const AddScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δz());
    }
    
    void        AScale³D::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³D::on_multiply_scale3(const MultiplyScale³DCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³D::on_multiply_scaleX(const MultiplyScaleˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale³D::on_multiply_scaleY(const MultiplyScaleʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
    
    void        AScale³D::on_multiply_scaleZ(const MultiplyScaleᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Z, cmd.δz());
    }
}
