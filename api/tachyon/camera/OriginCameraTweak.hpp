////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/CameraTweak.hpp>

namespace yq::tachyon {
    class OriginCameraTweak : public CameraTweak {
    public:
        OriginCameraTweak();
        
        virtual void    camera_tweak(Tensor44D& view, Tensor44D& proj) const override;
        
    protected:
        virtual ~OriginCameraTweak();
    };
}
