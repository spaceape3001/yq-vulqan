////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/scene/Perspective.hpp>
#include <tachyon/asset/NullCamera.hpp>

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
