////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon {
    struct CameraSnap : public TachyonSnap {
    };
    
    struct CameraData : public TachyonData {
    };
}
