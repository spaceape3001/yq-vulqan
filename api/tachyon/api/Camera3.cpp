////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>
#include <tachyon/api/Camera3InfoWriter.hpp>
#include <tachyon/command/SpatialCommand.hpp>
#include <tachyon/command/camera/CameraSetScreenCommand.hpp>
#include <tachyon/spatial/SimpleSpatial3.hpp>
#include <tachyon/api/3DWriter.hxx>
#include <yq/meta/Init.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Camera³ID)

namespace yq::tachyon {
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
        
        //  total hack (for now)
        m_screen.size.x = 1920;
        m_screen.size.y = 1080;
    }
    
    Camera³::~Camera³()
    {
    }
    

    void Camera³::finalize(Camera³Data&d) const
    {
        ③::finalize(d);
        Camera::finalize(d);
    }
    
    void Camera³::on_set_screen(const CameraSetScreenCommand& cmd)
    {
        if(cmd.target() == id()){
            m_screen        = cmd.screen();
            mark();
        }
    }
    
    void Camera³::snap(Camera³Snap& sn) const
    {
        ③::snap(sn);
        Camera::snap(sn);
        sn.screen   = m_screen;
    }

    void Camera³::init_info()
    {
        auto w = writer<Camera³>();
        ③::init_info(w);
        w.description("Camera in 3D");
        w.slot(&Camera³::on_set_screen);
        w.abstract();
        
        auto wt = writer<Camera³ID>();
        wt.description("3D Camera Identifier");
        wt.set(Meta::Flag::ID);
    }
}
