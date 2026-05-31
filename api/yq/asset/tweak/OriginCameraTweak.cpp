////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OriginCameraTweak.hpp"
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {
    OriginCameraTweak::OriginCameraTweak()
    {
    }
    
    OriginCameraTweak::~OriginCameraTweak()
    {
    }
        
    void    OriginCameraTweak::camera_tweak(Tensor44D& view, Tensor44D& proj) const
    {
        view.xw     = 0.;
        view.yw     = 0.;
        view.zw     = 0.;
        view.ww     = 1.;
    }
}
