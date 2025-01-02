////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/3D/Camera3.hpp>
#include <yq/tachyon/3D/Camera3Bind.hpp>
#include <yq/tachyon/3D/Camera3Data.hpp>
#include <yq/tachyon/3D/Camera3InfoWriter.hpp>
#include <yq/tachyon/spatials/SimpleSpatial3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera³)

namespace yq::tachyon {
    Camera³Info::Camera³Info(std::string_view name, CameraInfo& base, const std::source_location& sl) :
        CameraInfo(name, base, sl)
    {
        set(Type::Camera³);
    }

    Camera³Info::~Camera³Info()
    {
    }
    

    Camera³::Camera³(const Param& p) : Camera(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            SimpleSpatial³::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial³>(CHILD, p3) -> id();
            subscribe(m_spatial, MG::Spatial);
        }
    }
    
    Camera³::~Camera³()
    {
    }
    
    void Camera³::snap(Camera³Snap& sn) const
    {
        Camera::snap(sn);
    }
    
    void Camera³::init_info()
    {
        auto w = writer<Camera³>();
        w.description("Camera in 3D");
    }
}
