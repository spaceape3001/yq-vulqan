////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Perspective.hpp>
#include <yq-vulqan/camera/NullCamera.hpp>

namespace yq::tachyon {
    Perspective::Perspective()
    {
        camera = new NullCamera;
    }
    
    Perspective::~Perspective()
    {
    }
}
