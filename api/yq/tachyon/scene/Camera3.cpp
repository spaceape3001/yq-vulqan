////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera³.hpp"
#include "Camera³InfoWriter.hpp"

namespace yq::tachyon {
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
}
