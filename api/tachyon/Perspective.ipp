////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Perspective.hpp>
#include <tachyon/asset/NullCamera.hpp>

namespace yq::tachyon {
    Perspective::Perspective()
    {
        camera = new NullCamera;
    }
    
    Perspective::~Perspective()
    {
    }
}
