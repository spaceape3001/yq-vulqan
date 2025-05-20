////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/tensor44.hpp>
#include <yq/core/Ref.hpp>
#include <tachyon/typedef/camera.hpp>

namespace yq::tachyon {
    class CameraTweak : public RefCount {
    public:
        virtual void    camera_tweak(Tensor44D& view, Tensor44D& proj) const = 0;
    protected:
        friend CameraTweakCPtr;
        CameraTweak();
        virtual ~CameraTweak();
    };
}

