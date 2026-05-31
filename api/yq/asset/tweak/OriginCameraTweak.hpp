////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/CameraTweak.hpp>

namespace yq::tachyon {

    //! Camera tweak to ensure that the camera is always at the origin
    class OriginCameraTweak : public CameraTweak {
    public:
        OriginCameraTweak();
        
        virtual void    camera_tweak(Tensor44D& view, Tensor44D& proj) const override;
        
    protected:
        virtual ~OriginCameraTweak();
    };
}
