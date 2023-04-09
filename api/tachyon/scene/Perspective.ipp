////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/scene/Perspective.hpp>
#include <tachyon/camera/NullCamera.hpp>

namespace yq {
    namespace tachyon {
        Perspective::Perspective()
        {
            camera = new NullCamera;
        }
        
        Perspective::~Perspective()
        {
        }
    }
}
