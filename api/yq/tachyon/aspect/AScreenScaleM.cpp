////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AScreenScaleMWriter.hxx"

#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/command/scale/AddScaleMCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleMCommand.hpp>
#include <yq/tachyon/event/spatial/ScaleMEvent.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>


namespace yq::tachyon {
    AScreenScaleM::AScreenScaleM()
    {
    }
    
    AScreenScaleM::~AScreenScaleM()
    {
    }

    void        AScreenScaleM::screen_scale(emit_k)
    {
        send(new ScaleMEvent({.source=typed()}, m_screenScale));
    }

    void        AScreenScaleM::screen_scale(set_k, Meter sz) 
    {
        m_screenScale  =    sz;
        mark();
        screen_scale(EMIT);
    }
    
    void        AScreenScaleM::screen_scale(add_k, Meter v) 
    {
        screen_scale(SET, m_screenScale+v );
    }
    
    void        AScreenScaleM::screen_scale(multiply_k, double v) 
    {
        screen_scale(SET, m_screenScale*v );
    }
    
    void        AScreenScaleM::on_set_scale(const SetScaleMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        screen_scale(SET, cmd.scale());
    }
    
    void        AScreenScaleM::on_add_scale(const AddScaleMCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        screen_scale(ADD, cmd.Δscale());
    }
    
    void        AScreenScaleM::on_multiply_scale(const MultiplyScaleDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        screen_scale(MULTIPLY, cmd.δ());
    }

    void        AScreenScaleM::snap(ScreenScaleSnap&sn) const
    {
        // These implementations will likely move to an aspect....
        sn.screen2map   = [sc=m_screenScale](const Meter2D& pt) -> Vector2D {
            return { 
                pt.x.value/sc.value,
                pt.y.value/sc.value
            };
        };
        
        sn.screen2rev   = [sc=m_screenScale](const Vector2D& v) -> Meter2D {
            return {
                v.x * sc,
                v.y * sc
            };
        };

        sn.screen3map   = [sc=m_screenScale](const Meter3D& pt) -> Vector3D {
            return { 
                pt.x.value/sc.value,
                pt.y.value/sc.value,
                pt.z.value/sc.value
            };
        };

        sn.screen3rev   = [sc=m_screenScale](const Vector3D& v) -> Meter3D {
            return {
                v.x * sc,
                v.y * sc,
                v.z * sc
            };
        };
    }
}
