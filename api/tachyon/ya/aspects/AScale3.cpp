////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/aspects/AScale3.hpp>
#include <ya/commands/scale/AddScale3.hpp>
#include <ya/commands/scale/AddScaleX.hpp>
#include <ya/commands/scale/AddScaleY.hpp>
#include <ya/commands/scale/AddScaleZ.hpp>
#include <ya/commands/scale/MultiplyScale.hpp>
#include <ya/commands/scale/MultiplyScale3.hpp>
#include <ya/commands/scale/MultiplyScaleX.hpp>
#include <ya/commands/scale/MultiplyScaleY.hpp>
#include <ya/commands/scale/MultiplyScaleZ.hpp>
#include <ya/commands/scale/SetScale3.hpp>
#include <ya/commands/scale/SetScaleX.hpp>
#include <ya/commands/scale/SetScaleY.hpp>
#include <ya/commands/scale/SetScaleZ.hpp>
#include <ya/events/spatial/Scale3Event.hpp>


namespace yq::tachyon {
    AScale³::AScale³()
    {
    }
    
    AScale³::~AScale³()
    {
    }

    void        AScale³::scale(emit_k)
    {
        send(new Scale³Event({.source=typed()}, m_scale));
    }

    void        AScale³::scale(set_k, const Vector3D& sz) 
    {
        m_scale  =    sz;
        mark();
        scale(EMIT);
    }
    
    void        AScale³::scale(set_k, x_k, double v) 
    {
        scale(SET, Vector3D(v, m_scale.y, m_scale.z));
    }
    
    void        AScale³::scale(set_k, y_k, double v) 
    {
        scale(SET, Vector3D(m_scale.x,v, m_scale.z));
    }
    
    void        AScale³::scale(set_k, z_k, double v) 
    {
        scale(SET, Vector3D(m_scale.x, m_scale.y, v));
    }
    
    void        AScale³::scale(add_k, const Vector3D&v) 
    {
        scale(SET, Vector3D( m_scale.x+v.x, m_scale.y+v.y, m_scale.z+v.z ));
    }
    
    void        AScale³::scale(add_k, x_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x+v, m_scale.y, m_scale.z ));
    }
    
    void        AScale³::scale(add_k, y_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y+v, m_scale.z ));
    }
    
    void        AScale³::scale(add_k, z_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y, m_scale.z+v ));
    }

    void        AScale³::scale(multiply_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x*v, m_scale.y*v, m_scale.z*v ));
    }
    
    void        AScale³::scale(multiply_k, const Vector3D& v) 
    {
        scale(SET, Vector3D( m_scale.x*v.x, m_scale.y*v.y, m_scale.z*v.z ));
    }
    
    void        AScale³::scale(multiply_k, x_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x*v, m_scale.y, m_scale.z ));
    }
    
    void        AScale³::scale(multiply_k, y_k, double v) 
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y*v, m_scale.z ));
    }
    
    void        AScale³::scale(multiply_k, z_k, double v)
    {
        scale(SET, Vector3D( m_scale.x, m_scale.y, m_scale.z*v ));
    }
    
    void        AScale³::on_set_scale3(const SetScale³&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale³::on_set_scaleX(const SetScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale³::on_set_scaleY(const SetScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale³::on_set_scaleZ(const SetScaleᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Z, cmd.z());
    }

    void        AScale³::on_add_scale3(const AddScale³&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale³::on_add_scaleX(const AddScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale³::on_add_scaleY(const AddScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale³::on_add_scaleZ(const AddScaleᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δz());
    }
    
    void        AScale³::on_multiply_scale(const MultiplyScale&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³::on_multiply_scale3(const MultiplyScale³&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³::on_multiply_scaleX(const MultiplyScaleˣ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale³::on_multiply_scaleY(const MultiplyScaleʸ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
    
    void        AScale³::on_multiply_scaleZ(const MultiplyScaleᶻ&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Z, cmd.δz());
    }
}
