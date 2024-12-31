////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera3.hpp"
#include "Camera3InfoWriter.hpp"

namespace yq::tachyon {
    Camera3::Camera3(const Param& p) : Camera(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            SimpleSpatial3::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial3>(CHILD, p3) -> id();
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
}
