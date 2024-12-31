////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera3.hpp"
#include "Camera3InfoWriter.hpp"
#include <yq/tachyon/spatials/SimpleSpatial3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Camera3)

namespace yq::tachyon {
    Camera3Info::Camera3Info(std::string_view name, CameraInfo& base, const std::source_location& sl) :
        CameraInfo(name, base, sl)
    {
    }

    Camera3Info::~Camera3Info()
    {
    }
    

    Camera3::Camera3(const Param& p) : Camera(p)
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
    
    Camera3::~Camera3()
    {
    }
    
    void Camera3::snap(Camera3Snap& sn) const
    {
        Camera::snap(sn);
    }
    
    void Camera3::init_info()
    {
        auto w = writer<Camera3>();
        w.description("Camera in 3D");
    }
}
