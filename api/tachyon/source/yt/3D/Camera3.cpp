////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Bind.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/3D/Camera3InfoWriter.hpp>
#include <ya/commands/camera/CameraSetScreen.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/3D/3DWriter.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera³)

namespace yq::tachyon {
    Camera³Bind::Camera³Bind(const Camera³* v) : m_camera³(v?v->id():Camera³ID()) 
    {
    }
    
    Camera³Bind::Camera³Bind(TypedID t) : m_camera³(t(Type::Camera³) ? Camera³ID(t.id) : Camera³ID())
    {
    }

    /////////////////////////////////////////////////////////////////////////////

    Camera³Info::Camera³Info(std::string_view name, CameraInfo& base, const std::source_location& sl) :
        CameraInfo(name, base, sl)
    {
        set(Type::Camera³);
    }

    Camera³Info::~Camera³Info()
    {
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Camera³::Camera³(const Param& p) : Camera(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            make_simple_spatial(p.position, p.orientation, p.scale);
        }
    }
    
    Camera³::~Camera³()
    {
    }
    
    void Camera³::finalize(Camera³Data&d) const
    {
        ③::finalize(d);
        Camera::finalize(d);
    }
    
    void Camera³::on_set_screen(const CameraSetScreen& cmd)
    {
        if(cmd.camera() == id()){
            m_screen        = cmd.screen();
            mark();
        }
    }

    void Camera³::snap(Camera³Snap& sn) const
    {
        ③::snap(sn);
        Camera::snap(sn);
        sn.view     = domain2local();
        sn.screen   = m_screen;
    }

    void Camera³::init_info()
    {
        auto w = writer<Camera³>();
        ③::init_info(w);
        w.description("Camera in 3D");
        w.slot(&Camera³::on_set_screen);
    }
}
