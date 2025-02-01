////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TachyonData.hpp>
#include <yt/typedef/camera.hpp>

namespace yq::tachyon {
    struct CameraSnap : public TachyonSnap {
        glm::mat4       view, projection;
    };
    
    struct CameraData : public TachyonData {
    };
}
