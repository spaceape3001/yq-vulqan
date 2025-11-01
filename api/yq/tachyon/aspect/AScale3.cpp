////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/aspect/AScale3.hpp>
#include <yq/tachyon/command/scale/AddScale3Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZCommand.hpp>
#include <yq/tachyon/event/spatial/Scale3Event.hpp>


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
    
    void        AScale³::on_set_scale3(const SetScale³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, cmd.scale());
    }
    
    void        AScale³::on_set_scaleX(const SetScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, X, cmd.x());
    }
    
    void        AScale³::on_set_scaleY(const SetScaleʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Y, cmd.y());
    }
    
    void        AScale³::on_set_scaleZ(const SetScaleᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(SET, Z, cmd.z());
    }

    void        AScale³::on_add_scale3(const AddScale³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, cmd.Δ());
    }
    
    void        AScale³::on_add_scaleX(const AddScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δx());
    }
    
    void        AScale³::on_add_scaleY(const AddScaleʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δy());
    }
    
    void        AScale³::on_add_scaleZ(const AddScaleᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(ADD, X, cmd.Δz());
    }
    
    void        AScale³::on_multiply_scale(const MultiplyScaleCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³::on_multiply_scale3(const MultiplyScale³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, cmd.δ());
    }
    
    void        AScale³::on_multiply_scaleX(const MultiplyScaleˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, X, cmd.δx());
    }
    
    void        AScale³::on_multiply_scaleY(const MultiplyScaleʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Y, cmd.δy());
    }
    
    void        AScale³::on_multiply_scaleZ(const MultiplyScaleᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        scale(MULTIPLY, Z, cmd.δz());
    }
}
